/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl5666526234918278911.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl/android/hardware/input/common/Flag.aidl
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
enum class Flag : int32_t {
  WINDOW_IS_OBSCURED = 1,
  IS_GENERATED_GESTURE = 8,
  TAINTED = -2147483648,
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
[[nodiscard]] static inline std::string toString(Flag val) {
  switch(val) {
  case Flag::WINDOW_IS_OBSCURED:
    return "WINDOW_IS_OBSCURED";
  case Flag::IS_GENERATED_GESTURE:
    return "IS_GENERATED_GESTURE";
  case Flag::TAINTED:
    return "TAINTED";
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
constexpr inline std::array<aidl::android::hardware::input::common::Flag, 3> enum_values<aidl::android::hardware::input::common::Flag> = {
  aidl::android::hardware::input::common::Flag::WINDOW_IS_OBSCURED,
  aidl::android::hardware::input::common::Flag::IS_GENERATED_GESTURE,
  aidl::android::hardware::input::common::Flag::TAINTED,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
