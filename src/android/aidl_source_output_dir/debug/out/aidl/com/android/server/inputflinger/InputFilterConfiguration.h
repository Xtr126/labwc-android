/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl3459415451710280327.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl/com/android/server/inputflinger/InputFilterConfiguration.aidl
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
class InputFilterConfiguration {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  int64_t bounceKeysThresholdNs = 0L;
  bool stickyKeysEnabled = false;
  int64_t slowKeysThresholdNs = 0L;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const InputFilterConfiguration& _rhs) const {
    return std::tie(bounceKeysThresholdNs, stickyKeysEnabled, slowKeysThresholdNs) == std::tie(_rhs.bounceKeysThresholdNs, _rhs.stickyKeysEnabled, _rhs.slowKeysThresholdNs);
  }
  inline bool operator<(const InputFilterConfiguration& _rhs) const {
    return std::tie(bounceKeysThresholdNs, stickyKeysEnabled, slowKeysThresholdNs) < std::tie(_rhs.bounceKeysThresholdNs, _rhs.stickyKeysEnabled, _rhs.slowKeysThresholdNs);
  }
  inline bool operator!=(const InputFilterConfiguration& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const InputFilterConfiguration& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const InputFilterConfiguration& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const InputFilterConfiguration& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_LOCAL;
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "InputFilterConfiguration{";
    _aidl_os << "bounceKeysThresholdNs: " << ::android::internal::ToString(bounceKeysThresholdNs);
    _aidl_os << ", stickyKeysEnabled: " << ::android::internal::ToString(stickyKeysEnabled);
    _aidl_os << ", slowKeysThresholdNs: " << ::android::internal::ToString(slowKeysThresholdNs);
    _aidl_os << "}";
    return _aidl_os.str();
  }
};
}  // namespace inputflinger
}  // namespace server
}  // namespace android
}  // namespace com
}  // namespace aidl
