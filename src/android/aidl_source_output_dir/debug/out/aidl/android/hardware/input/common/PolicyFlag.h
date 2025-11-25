/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl11727273143103569673.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl/android/hardware/input/common/PolicyFlag.aidl
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
enum class PolicyFlag : int32_t {
  WAKE = 1,
  VIRTUAL = 2,
  FUNCTION = 4,
  GESTURE = 8,
  INJECTED = 16777216,
  TRUSTED = 33554432,
  FILTERED = 67108864,
  DISABLE_KEY_REPEAT = 134217728,
  INTERACTIVE = 536870912,
  PASS_TO_USER = 1073741824,
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
[[nodiscard]] static inline std::string toString(PolicyFlag val) {
  switch(val) {
  case PolicyFlag::WAKE:
    return "WAKE";
  case PolicyFlag::VIRTUAL:
    return "VIRTUAL";
  case PolicyFlag::FUNCTION:
    return "FUNCTION";
  case PolicyFlag::GESTURE:
    return "GESTURE";
  case PolicyFlag::INJECTED:
    return "INJECTED";
  case PolicyFlag::TRUSTED:
    return "TRUSTED";
  case PolicyFlag::FILTERED:
    return "FILTERED";
  case PolicyFlag::DISABLE_KEY_REPEAT:
    return "DISABLE_KEY_REPEAT";
  case PolicyFlag::INTERACTIVE:
    return "INTERACTIVE";
  case PolicyFlag::PASS_TO_USER:
    return "PASS_TO_USER";
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
constexpr inline std::array<aidl::android::hardware::input::common::PolicyFlag, 10> enum_values<aidl::android::hardware::input::common::PolicyFlag> = {
  aidl::android::hardware::input::common::PolicyFlag::WAKE,
  aidl::android::hardware::input::common::PolicyFlag::VIRTUAL,
  aidl::android::hardware::input::common::PolicyFlag::FUNCTION,
  aidl::android::hardware::input::common::PolicyFlag::GESTURE,
  aidl::android::hardware::input::common::PolicyFlag::INJECTED,
  aidl::android::hardware::input::common::PolicyFlag::TRUSTED,
  aidl::android::hardware::input::common::PolicyFlag::FILTERED,
  aidl::android::hardware::input::common::PolicyFlag::DISABLE_KEY_REPEAT,
  aidl::android::hardware::input::common::PolicyFlag::INTERACTIVE,
  aidl::android::hardware::input::common::PolicyFlag::PASS_TO_USER,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
