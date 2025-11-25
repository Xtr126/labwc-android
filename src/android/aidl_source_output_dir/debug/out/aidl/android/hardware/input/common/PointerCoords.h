/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl704666328723995757.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl/android/hardware/input/common/PointerCoords.aidl
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
namespace android {
namespace hardware {
namespace input {
namespace common {
class PointerCoords {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  int64_t bits = 0L;
  std::vector<float> values;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const PointerCoords& _rhs) const {
    return std::tie(bits, values) == std::tie(_rhs.bits, _rhs.values);
  }
  inline bool operator<(const PointerCoords& _rhs) const {
    return std::tie(bits, values) < std::tie(_rhs.bits, _rhs.values);
  }
  inline bool operator!=(const PointerCoords& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const PointerCoords& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const PointerCoords& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const PointerCoords& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_LOCAL;
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "PointerCoords{";
    _aidl_os << "bits: " << ::android::internal::ToString(bits);
    _aidl_os << ", values: " << ::android::internal::ToString(values);
    _aidl_os << "}";
    return _aidl_os.str();
  }
};
}  // namespace common
}  // namespace input
}  // namespace hardware
}  // namespace android
}  // namespace aidl
