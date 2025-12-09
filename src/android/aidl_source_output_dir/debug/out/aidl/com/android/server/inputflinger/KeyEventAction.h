/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl17138101475725949917.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl/com/android/server/inputflinger/KeyEventAction.aidl
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
namespace com {
namespace android {
namespace server {
namespace inputflinger {
enum class KeyEventAction : int8_t {
  DOWN = 0,
  UP = 1,
  MULTIPLE = 2,
};

}  // namespace inputflinger
}  // namespace server
}  // namespace android
}  // namespace com
}  // namespace aidl
namespace aidl {
namespace com {
namespace android {
namespace server {
namespace inputflinger {
[[nodiscard]] static inline std::string toString(KeyEventAction val) {
  switch(val) {
  case KeyEventAction::DOWN:
    return "DOWN";
  case KeyEventAction::UP:
    return "UP";
  case KeyEventAction::MULTIPLE:
    return "MULTIPLE";
  default:
    return std::to_string(static_cast<int8_t>(val));
  }
}
}  // namespace inputflinger
}  // namespace server
}  // namespace android
}  // namespace com
}  // namespace aidl
namespace ndk {
namespace internal {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<aidl::com::android::server::inputflinger::KeyEventAction, 3> enum_values<aidl::com::android::server::inputflinger::KeyEventAction> = {
  aidl::com::android::server::inputflinger::KeyEventAction::DOWN,
  aidl::com::android::server::inputflinger::KeyEventAction::UP,
  aidl::com::android::server::inputflinger::KeyEventAction::MULTIPLE,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
