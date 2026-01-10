/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl10256290632950055991.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl/android/hardware/input/common/Axis.aidl
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
enum class Axis : int32_t {
  X = 0,
  Y = 1,
  PRESSURE = 2,
  SIZE = 3,
  TOUCH_MAJOR = 4,
  TOUCH_MINOR = 5,
  TOOL_MAJOR = 6,
  TOOL_MINOR = 7,
  ORIENTATION = 8,
  VSCROLL = 9,
  HSCROLL = 10,
  Z = 11,
  RX = 12,
  RY = 13,
  RZ = 14,
  HAT_X = 15,
  HAT_Y = 16,
  LTRIGGER = 17,
  RTRIGGER = 18,
  THROTTLE = 19,
  RUDDER = 20,
  WHEEL = 21,
  GAS = 22,
  BRAKE = 23,
  DISTANCE = 24,
  TILT = 25,
  SCROLL = 26,
  RELATIVE_X = 27,
  RELATIVE_Y = 28,
  GENERIC_1 = 32,
  GENERIC_2 = 33,
  GENERIC_3 = 34,
  GENERIC_4 = 35,
  GENERIC_5 = 36,
  GENERIC_6 = 37,
  GENERIC_7 = 38,
  GENERIC_8 = 39,
  GENERIC_9 = 40,
  GENERIC_10 = 41,
  GENERIC_11 = 42,
  GENERIC_12 = 43,
  GENERIC_13 = 44,
  GENERIC_14 = 45,
  GENERIC_15 = 46,
  GENERIC_16 = 47,
  CAPTION_BAR_HEIGHT = 48,
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
[[nodiscard]] static inline std::string toString(Axis val) {
  switch(val) {
  case Axis::X:
    return "X";
  case Axis::Y:
    return "Y";
  case Axis::PRESSURE:
    return "PRESSURE";
  case Axis::SIZE:
    return "SIZE";
  case Axis::TOUCH_MAJOR:
    return "TOUCH_MAJOR";
  case Axis::TOUCH_MINOR:
    return "TOUCH_MINOR";
  case Axis::TOOL_MAJOR:
    return "TOOL_MAJOR";
  case Axis::TOOL_MINOR:
    return "TOOL_MINOR";
  case Axis::ORIENTATION:
    return "ORIENTATION";
  case Axis::VSCROLL:
    return "VSCROLL";
  case Axis::HSCROLL:
    return "HSCROLL";
  case Axis::Z:
    return "Z";
  case Axis::RX:
    return "RX";
  case Axis::RY:
    return "RY";
  case Axis::RZ:
    return "RZ";
  case Axis::HAT_X:
    return "HAT_X";
  case Axis::HAT_Y:
    return "HAT_Y";
  case Axis::LTRIGGER:
    return "LTRIGGER";
  case Axis::RTRIGGER:
    return "RTRIGGER";
  case Axis::THROTTLE:
    return "THROTTLE";
  case Axis::RUDDER:
    return "RUDDER";
  case Axis::WHEEL:
    return "WHEEL";
  case Axis::GAS:
    return "GAS";
  case Axis::BRAKE:
    return "BRAKE";
  case Axis::DISTANCE:
    return "DISTANCE";
  case Axis::TILT:
    return "TILT";
  case Axis::SCROLL:
    return "SCROLL";
  case Axis::RELATIVE_X:
    return "RELATIVE_X";
  case Axis::RELATIVE_Y:
    return "RELATIVE_Y";
  case Axis::GENERIC_1:
    return "GENERIC_1";
  case Axis::GENERIC_2:
    return "GENERIC_2";
  case Axis::GENERIC_3:
    return "GENERIC_3";
  case Axis::GENERIC_4:
    return "GENERIC_4";
  case Axis::GENERIC_5:
    return "GENERIC_5";
  case Axis::GENERIC_6:
    return "GENERIC_6";
  case Axis::GENERIC_7:
    return "GENERIC_7";
  case Axis::GENERIC_8:
    return "GENERIC_8";
  case Axis::GENERIC_9:
    return "GENERIC_9";
  case Axis::GENERIC_10:
    return "GENERIC_10";
  case Axis::GENERIC_11:
    return "GENERIC_11";
  case Axis::GENERIC_12:
    return "GENERIC_12";
  case Axis::GENERIC_13:
    return "GENERIC_13";
  case Axis::GENERIC_14:
    return "GENERIC_14";
  case Axis::GENERIC_15:
    return "GENERIC_15";
  case Axis::GENERIC_16:
    return "GENERIC_16";
  case Axis::CAPTION_BAR_HEIGHT:
    return "CAPTION_BAR_HEIGHT";
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
constexpr inline std::array<aidl::android::hardware::input::common::Axis, 46> enum_values<aidl::android::hardware::input::common::Axis> = {
  aidl::android::hardware::input::common::Axis::X,
  aidl::android::hardware::input::common::Axis::Y,
  aidl::android::hardware::input::common::Axis::PRESSURE,
  aidl::android::hardware::input::common::Axis::SIZE,
  aidl::android::hardware::input::common::Axis::TOUCH_MAJOR,
  aidl::android::hardware::input::common::Axis::TOUCH_MINOR,
  aidl::android::hardware::input::common::Axis::TOOL_MAJOR,
  aidl::android::hardware::input::common::Axis::TOOL_MINOR,
  aidl::android::hardware::input::common::Axis::ORIENTATION,
  aidl::android::hardware::input::common::Axis::VSCROLL,
  aidl::android::hardware::input::common::Axis::HSCROLL,
  aidl::android::hardware::input::common::Axis::Z,
  aidl::android::hardware::input::common::Axis::RX,
  aidl::android::hardware::input::common::Axis::RY,
  aidl::android::hardware::input::common::Axis::RZ,
  aidl::android::hardware::input::common::Axis::HAT_X,
  aidl::android::hardware::input::common::Axis::HAT_Y,
  aidl::android::hardware::input::common::Axis::LTRIGGER,
  aidl::android::hardware::input::common::Axis::RTRIGGER,
  aidl::android::hardware::input::common::Axis::THROTTLE,
  aidl::android::hardware::input::common::Axis::RUDDER,
  aidl::android::hardware::input::common::Axis::WHEEL,
  aidl::android::hardware::input::common::Axis::GAS,
  aidl::android::hardware::input::common::Axis::BRAKE,
  aidl::android::hardware::input::common::Axis::DISTANCE,
  aidl::android::hardware::input::common::Axis::TILT,
  aidl::android::hardware::input::common::Axis::SCROLL,
  aidl::android::hardware::input::common::Axis::RELATIVE_X,
  aidl::android::hardware::input::common::Axis::RELATIVE_Y,
  aidl::android::hardware::input::common::Axis::GENERIC_1,
  aidl::android::hardware::input::common::Axis::GENERIC_2,
  aidl::android::hardware::input::common::Axis::GENERIC_3,
  aidl::android::hardware::input::common::Axis::GENERIC_4,
  aidl::android::hardware::input::common::Axis::GENERIC_5,
  aidl::android::hardware::input::common::Axis::GENERIC_6,
  aidl::android::hardware::input::common::Axis::GENERIC_7,
  aidl::android::hardware::input::common::Axis::GENERIC_8,
  aidl::android::hardware::input::common::Axis::GENERIC_9,
  aidl::android::hardware::input::common::Axis::GENERIC_10,
  aidl::android::hardware::input::common::Axis::GENERIC_11,
  aidl::android::hardware::input::common::Axis::GENERIC_12,
  aidl::android::hardware::input::common::Axis::GENERIC_13,
  aidl::android::hardware::input::common::Axis::GENERIC_14,
  aidl::android::hardware::input::common::Axis::GENERIC_15,
  aidl::android::hardware::input::common::Axis::GENERIC_16,
  aidl::android::hardware::input::common::Axis::CAPTION_BAR_HEIGHT,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
