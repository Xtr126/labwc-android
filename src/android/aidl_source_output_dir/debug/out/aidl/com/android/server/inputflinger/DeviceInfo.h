/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl4146362608870152820.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl/com/android/server/inputflinger/DeviceInfo.aidl
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
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl {
namespace com {
namespace android {
namespace server {
namespace inputflinger {
class DeviceInfo {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  int32_t deviceId = 0;
  bool external = false;
  int32_t keyboardType = 0;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const DeviceInfo& _rhs) const {
    return std::tie(deviceId, external, keyboardType) == std::tie(_rhs.deviceId, _rhs.external, _rhs.keyboardType);
  }
  inline bool operator<(const DeviceInfo& _rhs) const {
    return std::tie(deviceId, external, keyboardType) < std::tie(_rhs.deviceId, _rhs.external, _rhs.keyboardType);
  }
  inline bool operator!=(const DeviceInfo& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const DeviceInfo& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const DeviceInfo& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const DeviceInfo& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_LOCAL;
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "DeviceInfo{";
    _aidl_os << "deviceId: " << ::android::internal::ToString(deviceId);
    _aidl_os << ", external: " << ::android::internal::ToString(external);
    _aidl_os << ", keyboardType: " << ::android::internal::ToString(keyboardType);
    _aidl_os << "}";
    return _aidl_os.str();
  }
};
}  // namespace inputflinger
}  // namespace server
}  // namespace android
}  // namespace com
}  // namespace aidl
