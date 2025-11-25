/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl4513848523985251018.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl/android/hardware/input/common/VideoFrame.aidl
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
class VideoFrame {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  std::vector<char16_t> data;
  int32_t height = 0;
  int32_t width = 0;
  int64_t timestamp = 0L;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const VideoFrame& _rhs) const {
    return std::tie(data, height, width, timestamp) == std::tie(_rhs.data, _rhs.height, _rhs.width, _rhs.timestamp);
  }
  inline bool operator<(const VideoFrame& _rhs) const {
    return std::tie(data, height, width, timestamp) < std::tie(_rhs.data, _rhs.height, _rhs.width, _rhs.timestamp);
  }
  inline bool operator!=(const VideoFrame& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const VideoFrame& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const VideoFrame& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const VideoFrame& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_LOCAL;
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "VideoFrame{";
    _aidl_os << "data: " << ::android::internal::ToString(data);
    _aidl_os << ", height: " << ::android::internal::ToString(height);
    _aidl_os << ", width: " << ::android::internal::ToString(width);
    _aidl_os << ", timestamp: " << ::android::internal::ToString(timestamp);
    _aidl_os << "}";
    return _aidl_os.str();
  }
};
}  // namespace common
}  // namespace input
}  // namespace hardware
}  // namespace android
}  // namespace aidl
