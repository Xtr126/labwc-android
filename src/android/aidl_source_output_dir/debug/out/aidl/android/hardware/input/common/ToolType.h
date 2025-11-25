/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl2929860285758667233.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl/android/hardware/input/common/ToolType.aidl
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
enum class ToolType : int8_t {
  UNKNOWN = 0,
  FINGER = 1,
  STYLUS = 2,
  MOUSE = 3,
  ERASER = 4,
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
[[nodiscard]] static inline std::string toString(ToolType val) {
  switch(val) {
  case ToolType::UNKNOWN:
    return "UNKNOWN";
  case ToolType::FINGER:
    return "FINGER";
  case ToolType::STYLUS:
    return "STYLUS";
  case ToolType::MOUSE:
    return "MOUSE";
  case ToolType::ERASER:
    return "ERASER";
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
constexpr inline std::array<aidl::android::hardware::input::common::ToolType, 5> enum_values<aidl::android::hardware::input::common::ToolType> = {
  aidl::android::hardware::input::common::ToolType::UNKNOWN,
  aidl::android::hardware::input::common::ToolType::FINGER,
  aidl::android::hardware::input::common::ToolType::STYLUS,
  aidl::android::hardware::input::common::ToolType::MOUSE,
  aidl::android::hardware::input::common::ToolType::ERASER,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
