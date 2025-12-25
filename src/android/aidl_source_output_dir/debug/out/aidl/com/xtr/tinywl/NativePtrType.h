/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl11153125597867337551.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl/com/xtr/tinywl/NativePtrType.aidl
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
namespace xtr {
namespace tinywl {
enum class NativePtrType : int8_t {
  VIEW = 0,
  OUTPUT = 1,
};

}  // namespace tinywl
}  // namespace xtr
}  // namespace com
}  // namespace aidl
namespace aidl {
namespace com {
namespace xtr {
namespace tinywl {
[[nodiscard]] static inline std::string toString(NativePtrType val) {
  switch(val) {
  case NativePtrType::VIEW:
    return "VIEW";
  case NativePtrType::OUTPUT:
    return "OUTPUT";
  default:
    return std::to_string(static_cast<int8_t>(val));
  }
}
}  // namespace tinywl
}  // namespace xtr
}  // namespace com
}  // namespace aidl
namespace ndk {
namespace internal {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<aidl::com::xtr::tinywl::NativePtrType, 2> enum_values<aidl::com::xtr::tinywl::NativePtrType> = {
  aidl::com::xtr::tinywl::NativePtrType::VIEW,
  aidl::com::xtr::tinywl::NativePtrType::OUTPUT,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace ndk
