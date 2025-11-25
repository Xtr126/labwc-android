/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl15464836911183056516.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl/android/hardware/input/common/PointerProperties.aidl
 */
#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include <android/binder_interface_utils.h>
#include <android/binder_parcelable_utils.h>
#include <android/binder_to_string.h>
#include <aidl/android/hardware/input/common/ToolType.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl {
namespace android {
namespace hardware {
namespace input {
namespace common {
class PointerProperties {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  int32_t id = 0;
  ::aidl::android::hardware::input::common::ToolType toolType = ::aidl::android::hardware::input::common::ToolType(0);

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const PointerProperties& _rhs) const {
    return std::tie(id, toolType) == std::tie(_rhs.id, _rhs.toolType);
  }
  inline bool operator<(const PointerProperties& _rhs) const {
    return std::tie(id, toolType) < std::tie(_rhs.id, _rhs.toolType);
  }
  inline bool operator!=(const PointerProperties& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const PointerProperties& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const PointerProperties& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const PointerProperties& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_LOCAL;
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "PointerProperties{";
    _aidl_os << "id: " << ::android::internal::ToString(id);
    _aidl_os << ", toolType: " << ::android::internal::ToString(toolType);
    _aidl_os << "}";
    return _aidl_os.str();
  }
};
}  // namespace common
}  // namespace input
}  // namespace hardware
}  // namespace android
}  // namespace aidl
