/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl28129530148606652.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl/android/hardware/input/common/Action.aidl
 */
#pragma once

#include <array>
#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include <android/binder_enums.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl {
namespace android {
namespace hardware {
namespace input {
namespace common {
enum class Action : int32_t {
  DOWN = 0,
  UP = 1,
  MOVE = 2,
  CANCEL = 3,
  OUTSIDE = 4,
  POINTER_DOWN = 5,
  POINTER_UP = 6,
  HOVER_MOVE = 7,
  SCROLL = 8,
  HOVER_ENTER = 9,
  HOVER_EXIT = 10,
  BUTTON_PRESS = 11,
  BUTTON_RELEASE = 12,
};

}  // namespace common
}  // namespace input
}  // namespace hardware
}  // namespace android
}  // namespace aidl
namespace aidl {
namespace android {
namespace hardware {
namespace input {
namespace common {
[[nodiscard]] static inline std::string toString(Action val) {
  switch(val) {
  case Action::DOWN:
    return "DOWN";
  case Action::UP:
    return "UP";
  case Action::MOVE:
    return "MOVE";
  case Action::CANCEL:
    return "CANCEL";
  case Action::OUTSIDE:
    return "OUTSIDE";
  case Action::POINTER_DOWN:
    return "POINTER_DOWN";
  case Action::POINTER_UP:
    return "POINTER_UP";
  case Action::HOVER_MOVE:
    return "HOVER_MOVE";
  case Action::SCROLL:
    return "SCROLL";
  case Action::HOVER_ENTER:
    return "HOVER_ENTER";
  case Action::HOVER_EXIT:
    return "HOVER_EXIT";
  case Action::BUTTON_PRESS:
    return "BUTTON_PRESS";
  case Action::BUTTON_RELEASE:
    return "BUTTON_RELEASE";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}
}  // namespace common
}  // namespace input
}  // namespace hardware
}  // namespace android
}  // namespace aidl
namespace ndk {
namespace internal {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<aidl::android::hardware::input::common::Action, 13> enum_values<aidl::android::hardware::input::common::Action> = {
  aidl::android::hardware::input::common::Action::DOWN,
  aidl::android::hardware::input::common::Action::UP,
  aidl::android::hardware::input::common::Action::MOVE,
  aidl::android::hardware::input::common::Action::CANCEL,
  aidl::android::hardware::input::common::Action::OUTSIDE,
  aidl::android::hardware::input::common::Action::POINTER_DOWN,
  aidl::android::hardware::input::common::Action::POINTER_UP,
  aidl::android::hardware::input::common::Action::HOVER_MOVE,
  aidl::android::hardware::input::common::Action::SCROLL,
  aidl::android::hardware::input::common::Action::HOVER_ENTER,
  aidl::android::hardware::input::common::Action::HOVER_EXIT,
  aidl::android::hardware::input::common::Action::BUTTON_PRESS,
  aidl::android::hardware::input::common::Action::BUTTON_RELEASE,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
