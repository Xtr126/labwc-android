/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl16190319382023016615.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl/android/hardware/input/common/EdgeFlag.aidl
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
enum class EdgeFlag : int32_t {
  NONE = 0,
  TOP = 1,
  BOTTOM = 2,
  LEFT = 4,
  RIGHT = 8,
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
[[nodiscard]] static inline std::string toString(EdgeFlag val) {
  switch(val) {
  case EdgeFlag::NONE:
    return "NONE";
  case EdgeFlag::TOP:
    return "TOP";
  case EdgeFlag::BOTTOM:
    return "BOTTOM";
  case EdgeFlag::LEFT:
    return "LEFT";
  case EdgeFlag::RIGHT:
    return "RIGHT";
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
constexpr inline std::array<aidl::android::hardware::input::common::EdgeFlag, 5> enum_values<aidl::android::hardware::input::common::EdgeFlag> = {
  aidl::android::hardware::input::common::EdgeFlag::NONE,
  aidl::android::hardware::input::common::EdgeFlag::TOP,
  aidl::android::hardware::input::common::EdgeFlag::BOTTOM,
  aidl::android::hardware::input::common::EdgeFlag::LEFT,
  aidl::android::hardware::input::common::EdgeFlag::RIGHT,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
