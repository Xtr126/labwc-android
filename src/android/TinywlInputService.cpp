#include "aidl/android/hardware/input/common/Axis.h"
#include "aidl/android/hardware/input/common/MotionEvent.h"
#include "aidl/com/android/server/inputflinger/KeyEvent.h"
#include <aidl/tinywl/BnTinywlInput.h>
#include <android/keycodes.h>
#include <cstdint>
#include <stdint.h>
#include <wayland-server-core.h>
#include <wayland-server-protocol.h>
#include <sys/eventfd.h>
#include "TinywlInputService.hpp"
#include <android/input.h>

extern "C" {
  #include "view.h"
  #include <wlr/interfaces/wlr_keyboard.h>
  #include <wlr/interfaces/wlr_pointer.h>
  #include <linux/input-event-codes.h>
  #include <wlr/util/log.h>
}


static float PointerCoords_getAxisValue(const aidl::android::hardware::input::common::PointerCoords& coords, int32_t axis) {
    struct BitSet64 {
        uint64_t value;

        inline BitSet64() : value(0ULL) { }

        // Gets the value associated with a particular bit index.
        static inline uint64_t valueForBit(uint32_t n) { return 0x8000000000000000ULL >> n; }

        static inline bool hasBit(uint64_t value, uint32_t n) { return value & valueForBit(n); }

        static inline uint32_t getIndexOfBit(uint64_t value, uint32_t n) {
            return static_cast<uint32_t>(__builtin_popcountll(value & ~(0xffffffffffffffffULL >> n)));
        }
    };
    if (axis < 0 || axis > AMOTION_EVENT_MAXIMUM_VALID_AXIS_VALUE || !BitSet64::hasBit(coords.bits, axis)){
        return 0;
    }
    return coords.values[BitSet64::getIndexOfBit(coords.bits, axis)];
}

namespace tinywl {

    const static struct wlr_pointer_impl tinywl_pointer_impl = {
        .name = "tinywl-pointer",
    };

    const static struct wlr_keyboard_impl tinywl_keyboard_impl = {
        .name = "tinywl-keyboard",
    };


    void TinywlInputService::sendPointerButtonEvent(const MotionEvent& in_event, struct view *view) {
      struct wlr_pointer_button_event wlr_event = {
          .pointer = &pointer,
          .time_msec = (uint32_t)in_event.eventTime,
          .button = AKEYCODE_BUTTON_1,
          .state = WL_POINTER_BUTTON_STATE_PRESSED,
      };

      switch (in_event.action) {
        case Action::BUTTON_PRESS:
            wlr_event.state = WL_POINTER_BUTTON_STATE_PRESSED;
            break;
        case Action::BUTTON_RELEASE:
            wlr_event.state = WL_POINTER_BUTTON_STATE_RELEASED;
            break;
        default:
            return;
      }

      switch (in_event.actionButton) {
        case Button::PRIMARY:
            wlr_event.button = BTN_LEFT;
            break;
        case Button::SECONDARY:
            wlr_event.button = BTN_RIGHT;
            break;
        default:
            return;
      }

      wl_signal_emit_mutable(&pointer.events.button, &wlr_event);
      wl_signal_emit_mutable(&pointer.events.frame, &pointer);
    }

    void TinywlInputService::sendPointerPosition(const MotionEvent& in_event, struct view *view) {
      float x = PointerCoords_getAxisValue(in_event.pointerCoords.front(), static_cast<int32_t>(Axis::X));
      float y = PointerCoords_getAxisValue(in_event.pointerCoords.front(), static_cast<int32_t>(Axis::Y));
      x += view->current.x;
      y += view->current.y;
      
      struct wlr_pointer_motion_absolute_event wlr_event = {
        .pointer = &pointer,
        .time_msec = static_cast<uint32_t>(in_event.eventTime),
        .x = x / width,
        .y = y / height,
      };

      wl_signal_emit_mutable(&pointer.events.motion_absolute, &wlr_event);
      wl_signal_emit_mutable(&pointer.events.frame, &pointer);
    }

    void TinywlInputService::sendScrollEvent(const MotionEvent& in_event, struct view *view) {
      float delta = PointerCoords_getAxisValue(in_event.pointerCoords.front(), static_cast<int32_t>(Axis::Y));
      struct wlr_pointer_axis_event wlr_event = {
        .pointer = &pointer,
        .time_msec = static_cast<uint32_t>(in_event.eventTime),
        .source = WL_POINTER_AXIS_SOURCE_WHEEL,
        .orientation = WL_POINTER_AXIS_VERTICAL_SCROLL,
        .delta = delta,
        .delta_discrete = static_cast<int32_t>(delta * WLR_POINTER_AXIS_DISCRETE_STEP),
      };
      
      wl_signal_emit_mutable(&pointer.events.axis, &wlr_event);
      wl_signal_emit_mutable(&pointer.events.frame, &pointer);

    }

    ::ndk::ScopedAStatus TinywlInputService::onKeyEvent(const KeyEvent& in_event, long in_nativePtr, bool* _aidl_return) {
      keyEventQueue.push(in_event, in_nativePtr);
      eventfd_write(event_fd, 1);  // Notify event loop
      // std::cout << in_event.toString() << std::endl;
      *_aidl_return = true;
      return ::ndk::ScopedAStatus::ok();
    }
    ::ndk::ScopedAStatus TinywlInputService::onMotionEvent(const MotionEvent& in_event, long in_nativePtr, bool* _aidl_return) {
      motionEventQueue.push(in_event, in_nativePtr);
      eventfd_write(event_fd, 1);  // Notify event loop
      // std::cout << in_event.toString() << std::endl;
      *_aidl_return = true;
      return ::ndk::ScopedAStatus::ok();
    }

    static int event_loop_fd_callback(int fd, uint32_t mask, void *data) {
        auto thiz = reinterpret_cast<TinywlInputService *>(data);
        if ((mask & WL_EVENT_HANGUP) || (mask & WL_EVENT_ERROR)) {
            if (mask & WL_EVENT_ERROR) {
                wlr_log(WLR_ERROR, "Failed to read event");
            }
            return 0;
        }

        eventfd_t event_count = 0;
        if (eventfd_read(thiz->event_fd, &event_count) < 0) {
            return 0;
        }

        while (auto in_event = thiz->motionEventQueue.pull()) {
          // Process event
          if (in_event->event.source != Source::MOUSE) {
            continue;
          }

          struct view* view = reinterpret_cast<struct view*>(in_event->nativePtr);
          
          std::lock_guard<std::mutex> lock(thiz->mutex_);
          if (thiz->views.find(view) == thiz->views.end()) {
            continue;
          }

          switch (in_event->event.action) {
            case Action::BUTTON_PRESS:
            case Action::BUTTON_RELEASE:
              thiz->sendPointerButtonEvent(in_event->event, view);
              break;
            case Action::MOVE:
            case Action::HOVER_ENTER:
            case Action::HOVER_EXIT:
              thiz->sendPointerPosition(in_event->event, view);
              break;
            case Action::SCROLL:
              thiz->sendScrollEvent(in_event->event, view);
              break;
            default:
                // Skip other actions
                continue;
          }
        }

        while (auto in_event = thiz->keyEventQueue.pull()) {
          // Process event
          if (in_event->event.source != Source::KEYBOARD) {
            continue;
          }
          
          struct view* view = reinterpret_cast<struct view*>(in_event->nativePtr);
          
          std::lock_guard<std::mutex> lock(thiz->mutex_);
          if (thiz->views.find(view) == thiz->views.end()) {
            continue;
          }

          struct wlr_keyboard_key_event wlr_event = {
              .time_msec = static_cast<uint32_t>(in_event->event.eventTime),
              .keycode = (uint32_t)in_event->event.scanCode,
              .update_state = true,
          };

          switch (in_event->event.action) {
            case KeyEventAction::DOWN:
                wlr_event.state = WL_KEYBOARD_KEY_STATE_PRESSED;
                break;
            case KeyEventAction::UP:
                wlr_event.state = WL_KEYBOARD_KEY_STATE_RELEASED;
                break;
            default:
                // Skip other actions like AKEY_EVENT_ACTION_MULTIPLE
                continue;
          }

          wlr_keyboard_notify_key(&thiz->keyboard, &wlr_event);
        }
        return 0;
    }

    void TinywlInputService::setTinywlServer(struct server* server) {
      this->server = server;
      wlr_keyboard_init(&keyboard, &tinywl_keyboard_impl, "tinywl-keyboard");
      server->seat.new_input.notify(&server->seat.new_input, &keyboard.base);

      wlr_pointer_init(&pointer, &tinywl_pointer_impl, "tinywl-pointer");
      server->seat.new_input.notify(&server->seat.new_input, &pointer.base);
      
      /* Event loop and file descriptors */
      struct wl_event_loop *loop = wl_display_get_event_loop(server->wl_display);
      event_fd = eventfd(0, EFD_CLOEXEC | EFD_NONBLOCK | EFD_SEMAPHORE);

      uint32_t events = WL_EVENT_READABLE | WL_EVENT_ERROR | WL_EVENT_HANGUP;
      event_source = wl_event_loop_add_fd(loop, event_fd, events, event_loop_fd_callback, this);

    }

    void TinywlInputService::closeFdsAndRemoveEventSources() {
      wl_event_source_remove(event_source);
      close(event_fd);
    }
} // namespace tinywl

