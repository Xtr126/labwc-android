/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl10643894001605320254.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl/android/hardware/input/common/Source.aidl
 */
#pragma once

#include <array>
#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include <android/binder_enums.h>
#include <aidl/android/hardware/input/common/SourceClass.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl {
namespace android {
namespace hardware {
namespace input {
namespace common {
enum class Source : int32_t {
  UNKNOWN = 0,
  KEYBOARD = 257,
  DPAD = 513,
  GAMEPAD = 1025,
  TOUCHSCREEN = 4098,
  MOUSE = 8194,
  STYLUS = 16386,
  BLUETOOTH_STYLUS = 49154,
  TRACKBALL = 65540,
  MOUSE_RELATIVE = 131076,
  TOUCHPAD = 1048584,
  TOUCH_NAVIGATION = 2097152,
  ROTARY_ENCODER = 4194304,
  JOYSTICK = 16777232,
  HDMI = 33554433,
  SENSOR = 67108864,
  ANY = -256,
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
[[nodiscard]] static inline std::string toString(Source val) {
  switch(val) {
  case Source::UNKNOWN:
    return "UNKNOWN";
  case Source::KEYBOARD:
    return "KEYBOARD";
  case Source::DPAD:
    return "DPAD";
  case Source::GAMEPAD:
    return "GAMEPAD";
  case Source::TOUCHSCREEN:
    return "TOUCHSCREEN";
  case Source::MOUSE:
    return "MOUSE";
  case Source::STYLUS:
    return "STYLUS";
  case Source::BLUETOOTH_STYLUS:
    return "BLUETOOTH_STYLUS";
  case Source::TRACKBALL:
    return "TRACKBALL";
  case Source::MOUSE_RELATIVE:
    return "MOUSE_RELATIVE";
  case Source::TOUCHPAD:
    return "TOUCHPAD";
  case Source::TOUCH_NAVIGATION:
    return "TOUCH_NAVIGATION";
  case Source::ROTARY_ENCODER:
    return "ROTARY_ENCODER";
  case Source::JOYSTICK:
    return "JOYSTICK";
  case Source::HDMI:
    return "HDMI";
  case Source::SENSOR:
    return "SENSOR";
  case Source::ANY:
    return "ANY";
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
constexpr inline std::array<aidl::android::hardware::input::common::Source, 17> enum_values<aidl::android::hardware::input::common::Source> = {
  aidl::android::hardware::input::common::Source::UNKNOWN,
  aidl::android::hardware::input::common::Source::KEYBOARD,
  aidl::android::hardware::input::common::Source::DPAD,
  aidl::android::hardware::input::common::Source::GAMEPAD,
  aidl::android::hardware::input::common::Source::TOUCHSCREEN,
  aidl::android::hardware::input::common::Source::MOUSE,
  aidl::android::hardware::input::common::Source::STYLUS,
  aidl::android::hardware::input::common::Source::BLUETOOTH_STYLUS,
  aidl::android::hardware::input::common::Source::TRACKBALL,
  aidl::android::hardware::input::common::Source::MOUSE_RELATIVE,
  aidl::android::hardware::input::common::Source::TOUCHPAD,
  aidl::android::hardware::input::common::Source::TOUCH_NAVIGATION,
  aidl::android::hardware::input::common::Source::ROTARY_ENCODER,
  aidl::android::hardware::input::common::Source::JOYSTICK,
  aidl::android::hardware::input::common::Source::HDMI,
  aidl::android::hardware::input::common::Source::SENSOR,
  aidl::android::hardware::input::common::Source::ANY,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
