/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl11359802476421834658.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl/android/hardware/input/common/Classification.aidl
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
enum class Classification : int8_t {
  NONE = 0,
  AMBIGUOUS_GESTURE = 1,
  DEEP_PRESS = 2,
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
[[nodiscard]] static inline std::string toString(Classification val) {
  switch(val) {
  case Classification::NONE:
    return "NONE";
  case Classification::AMBIGUOUS_GESTURE:
    return "AMBIGUOUS_GESTURE";
  case Classification::DEEP_PRESS:
    return "DEEP_PRESS";
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
constexpr inline std::array<aidl::android::hardware::input::common::Classification, 3> enum_values<aidl::android::hardware::input::common::Classification> = {
  aidl::android::hardware::input::common::Classification::NONE,
  aidl::android::hardware::input::common::Classification::AMBIGUOUS_GESTURE,
  aidl::android::hardware::input::common::Classification::DEEP_PRESS,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
