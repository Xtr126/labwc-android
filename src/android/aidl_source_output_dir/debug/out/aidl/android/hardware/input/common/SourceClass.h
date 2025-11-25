/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl14098352424130655172.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl/android/hardware/input/common/SourceClass.aidl
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
enum class SourceClass : int8_t {
  NONE = 0,
  BUTTON = 1,
  POINTER = 2,
  NAVIGATION = 4,
  POSITION = 8,
  JOYSTICK = 16,
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
[[nodiscard]] static inline std::string toString(SourceClass val) {
  switch(val) {
  case SourceClass::NONE:
    return "NONE";
  case SourceClass::BUTTON:
    return "BUTTON";
  case SourceClass::POINTER:
    return "POINTER";
  case SourceClass::NAVIGATION:
    return "NAVIGATION";
  case SourceClass::POSITION:
    return "POSITION";
  case SourceClass::JOYSTICK:
    return "JOYSTICK";
  default:
    return std::to_string(static_cast<int8_t>(val));
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
constexpr inline std::array<aidl::android::hardware::input::common::SourceClass, 6> enum_values<aidl::android::hardware::input::common::SourceClass> = {
  aidl::android::hardware::input::common::SourceClass::NONE,
  aidl::android::hardware::input::common::SourceClass::BUTTON,
  aidl::android::hardware::input::common::SourceClass::POINTER,
  aidl::android::hardware::input::common::SourceClass::NAVIGATION,
  aidl::android::hardware::input::common::SourceClass::POSITION,
  aidl::android::hardware::input::common::SourceClass::JOYSTICK,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
