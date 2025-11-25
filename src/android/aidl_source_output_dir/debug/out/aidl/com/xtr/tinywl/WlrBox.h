/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl2886998968484122450.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl/com/xtr/tinywl/WlrBox.aidl
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
namespace xtr {
namespace tinywl {
class WlrBox {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  int32_t x = 0;
  int32_t y = 0;
  int32_t width = 0;
  int32_t height = 0;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const WlrBox& _rhs) const {
    return std::tie(x, y, width, height) == std::tie(_rhs.x, _rhs.y, _rhs.width, _rhs.height);
  }
  inline bool operator<(const WlrBox& _rhs) const {
    return std::tie(x, y, width, height) < std::tie(_rhs.x, _rhs.y, _rhs.width, _rhs.height);
  }
  inline bool operator!=(const WlrBox& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const WlrBox& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const WlrBox& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const WlrBox& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_LOCAL;
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "WlrBox{";
    _aidl_os << "x: " << ::android::internal::ToString(x);
    _aidl_os << ", y: " << ::android::internal::ToString(y);
    _aidl_os << ", width: " << ::android::internal::ToString(width);
    _aidl_os << ", height: " << ::android::internal::ToString(height);
    _aidl_os << "}";
    return _aidl_os.str();
  }
};
}  // namespace tinywl
}  // namespace xtr
}  // namespace com
}  // namespace aidl
