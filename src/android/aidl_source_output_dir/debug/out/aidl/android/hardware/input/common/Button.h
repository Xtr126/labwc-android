/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl11364753664143554536.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl/android/hardware/input/common/Button.aidl
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
enum class Button : int32_t {
  NONE = 0,
  PRIMARY = 1,
  SECONDARY = 2,
  TERTIARY = 4,
  BACK = 8,
  FORWARD = 16,
  STYLUS_PRIMARY = 32,
  STYLUS_SECONDARY = 64,
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
[[nodiscard]] static inline std::string toString(Button val) {
  switch(val) {
  case Button::NONE:
    return "NONE";
  case Button::PRIMARY:
    return "PRIMARY";
  case Button::SECONDARY:
    return "SECONDARY";
  case Button::TERTIARY:
    return "TERTIARY";
  case Button::BACK:
    return "BACK";
  case Button::FORWARD:
    return "FORWARD";
  case Button::STYLUS_PRIMARY:
    return "STYLUS_PRIMARY";
  case Button::STYLUS_SECONDARY:
    return "STYLUS_SECONDARY";
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
constexpr inline std::array<aidl::android::hardware::input::common::Button, 8> enum_values<aidl::android::hardware::input::common::Button> = {
  aidl::android::hardware::input::common::Button::NONE,
  aidl::android::hardware::input::common::Button::PRIMARY,
  aidl::android::hardware::input::common::Button::SECONDARY,
  aidl::android::hardware::input::common::Button::TERTIARY,
  aidl::android::hardware::input::common::Button::BACK,
  aidl::android::hardware::input::common::Button::FORWARD,
  aidl::android::hardware::input::common::Button::STYLUS_PRIMARY,
  aidl::android::hardware::input::common::Button::STYLUS_SECONDARY,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
