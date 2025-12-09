/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl17674885434006937264.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl/android/hardware/input/common/Meta.aidl
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
enum class Meta : int32_t {
  NONE = 0,
  ALT_ON = 2,
  ALT_LEFT_ON = 16,
  ALT_RIGHT_ON = 32,
  SHIFT_ON = 1,
  SHIFT_LEFT_ON = 64,
  SHIFT_RIGHT_ON = 128,
  SYM_ON = 4,
  FUNCTION_ON = 8,
  CTRL_ON = 4096,
  CTRL_LEFT_ON = 8192,
  CTRL_RIGHT_ON = 16384,
  META_ON = 65536,
  META_LEFT_ON = 131072,
  META_RIGHT_ON = 262144,
  CAPS_LOCK_ON = 1048576,
  NUM_LOCK_ON = 2097152,
  SCROLL_LOCK_ON = 4194304,
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
[[nodiscard]] static inline std::string toString(Meta val) {
  switch(val) {
  case Meta::NONE:
    return "NONE";
  case Meta::ALT_ON:
    return "ALT_ON";
  case Meta::ALT_LEFT_ON:
    return "ALT_LEFT_ON";
  case Meta::ALT_RIGHT_ON:
    return "ALT_RIGHT_ON";
  case Meta::SHIFT_ON:
    return "SHIFT_ON";
  case Meta::SHIFT_LEFT_ON:
    return "SHIFT_LEFT_ON";
  case Meta::SHIFT_RIGHT_ON:
    return "SHIFT_RIGHT_ON";
  case Meta::SYM_ON:
    return "SYM_ON";
  case Meta::FUNCTION_ON:
    return "FUNCTION_ON";
  case Meta::CTRL_ON:
    return "CTRL_ON";
  case Meta::CTRL_LEFT_ON:
    return "CTRL_LEFT_ON";
  case Meta::CTRL_RIGHT_ON:
    return "CTRL_RIGHT_ON";
  case Meta::META_ON:
    return "META_ON";
  case Meta::META_LEFT_ON:
    return "META_LEFT_ON";
  case Meta::META_RIGHT_ON:
    return "META_RIGHT_ON";
  case Meta::CAPS_LOCK_ON:
    return "CAPS_LOCK_ON";
  case Meta::NUM_LOCK_ON:
    return "NUM_LOCK_ON";
  case Meta::SCROLL_LOCK_ON:
    return "SCROLL_LOCK_ON";
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
constexpr inline std::array<aidl::android::hardware::input::common::Meta, 18> enum_values<aidl::android::hardware::input::common::Meta> = {
  aidl::android::hardware::input::common::Meta::NONE,
  aidl::android::hardware::input::common::Meta::ALT_ON,
  aidl::android::hardware::input::common::Meta::ALT_LEFT_ON,
  aidl::android::hardware::input::common::Meta::ALT_RIGHT_ON,
  aidl::android::hardware::input::common::Meta::SHIFT_ON,
  aidl::android::hardware::input::common::Meta::SHIFT_LEFT_ON,
  aidl::android::hardware::input::common::Meta::SHIFT_RIGHT_ON,
  aidl::android::hardware::input::common::Meta::SYM_ON,
  aidl::android::hardware::input::common::Meta::FUNCTION_ON,
  aidl::android::hardware::input::common::Meta::CTRL_ON,
  aidl::android::hardware::input::common::Meta::CTRL_LEFT_ON,
  aidl::android::hardware::input::common::Meta::CTRL_RIGHT_ON,
  aidl::android::hardware::input::common::Meta::META_ON,
  aidl::android::hardware::input::common::Meta::META_LEFT_ON,
  aidl::android::hardware::input::common::Meta::META_RIGHT_ON,
  aidl::android::hardware::input::common::Meta::CAPS_LOCK_ON,
  aidl::android::hardware::input::common::Meta::NUM_LOCK_ON,
  aidl::android::hardware::input::common::Meta::SCROLL_LOCK_ON,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
