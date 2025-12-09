/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl5301061338565715060.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl/com/android/server/inputflinger/KeyEvent.aidl
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
#include <aidl/android/hardware/input/common/Source.h>
#include <aidl/com/android/server/inputflinger/KeyEventAction.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl {
namespace com {
namespace android {
namespace server {
namespace inputflinger {
class KeyEvent {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  int32_t id = 0;
  int32_t deviceId = 0;
  int64_t downTime = 0L;
  int64_t readTime = 0L;
  int64_t eventTime = 0L;
  ::aidl::android::hardware::input::common::Source source = ::aidl::android::hardware::input::common::Source(0);
  int32_t displayId = 0;
  int32_t policyFlags = 0;
  ::aidl::com::android::server::inputflinger::KeyEventAction action = ::aidl::com::android::server::inputflinger::KeyEventAction(0);
  int32_t flags = 0;
  int32_t keyCode = 0;
  int32_t scanCode = 0;
  int32_t metaState = 0;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const KeyEvent& _rhs) const {
    return std::tie(id, deviceId, downTime, readTime, eventTime, source, displayId, policyFlags, action, flags, keyCode, scanCode, metaState) == std::tie(_rhs.id, _rhs.deviceId, _rhs.downTime, _rhs.readTime, _rhs.eventTime, _rhs.source, _rhs.displayId, _rhs.policyFlags, _rhs.action, _rhs.flags, _rhs.keyCode, _rhs.scanCode, _rhs.metaState);
  }
  inline bool operator<(const KeyEvent& _rhs) const {
    return std::tie(id, deviceId, downTime, readTime, eventTime, source, displayId, policyFlags, action, flags, keyCode, scanCode, metaState) < std::tie(_rhs.id, _rhs.deviceId, _rhs.downTime, _rhs.readTime, _rhs.eventTime, _rhs.source, _rhs.displayId, _rhs.policyFlags, _rhs.action, _rhs.flags, _rhs.keyCode, _rhs.scanCode, _rhs.metaState);
  }
  inline bool operator!=(const KeyEvent& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const KeyEvent& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const KeyEvent& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const KeyEvent& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_LOCAL;
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "KeyEvent{";
    _aidl_os << "id: " << ::android::internal::ToString(id);
    _aidl_os << ", deviceId: " << ::android::internal::ToString(deviceId);
    _aidl_os << ", downTime: " << ::android::internal::ToString(downTime);
    _aidl_os << ", readTime: " << ::android::internal::ToString(readTime);
    _aidl_os << ", eventTime: " << ::android::internal::ToString(eventTime);
    _aidl_os << ", source: " << ::android::internal::ToString(source);
    _aidl_os << ", displayId: " << ::android::internal::ToString(displayId);
    _aidl_os << ", policyFlags: " << ::android::internal::ToString(policyFlags);
    _aidl_os << ", action: " << ::android::internal::ToString(action);
    _aidl_os << ", flags: " << ::android::internal::ToString(flags);
    _aidl_os << ", keyCode: " << ::android::internal::ToString(keyCode);
    _aidl_os << ", scanCode: " << ::android::internal::ToString(scanCode);
    _aidl_os << ", metaState: " << ::android::internal::ToString(metaState);
    _aidl_os << "}";
    return _aidl_os.str();
  }
};
}  // namespace inputflinger
}  // namespace server
}  // namespace android
}  // namespace com
}  // namespace aidl
