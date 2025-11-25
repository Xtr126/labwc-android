/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl10303450148782488994.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl/android/hardware/input/common/MotionEvent.aidl
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
#include <aidl/android/hardware/input/common/Action.h>
#include <aidl/android/hardware/input/common/Button.h>
#include <aidl/android/hardware/input/common/EdgeFlag.h>
#include <aidl/android/hardware/input/common/Flag.h>
#include <aidl/android/hardware/input/common/Meta.h>
#include <aidl/android/hardware/input/common/PointerCoords.h>
#include <aidl/android/hardware/input/common/PointerProperties.h>
#include <aidl/android/hardware/input/common/PolicyFlag.h>
#include <aidl/android/hardware/input/common/Source.h>
#include <aidl/android/hardware/input/common/VideoFrame.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl::android::hardware::input::common {
class PointerCoords;
class PointerProperties;
class VideoFrame;
}  // namespace aidl::android::hardware::input::common
namespace aidl {
namespace android {
namespace hardware {
namespace input {
namespace common {
class MotionEvent {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  int32_t deviceId = 0;
  ::aidl::android::hardware::input::common::Source source = ::aidl::android::hardware::input::common::Source(0);
  int32_t displayId = 0;
  int64_t downTime = 0L;
  int64_t eventTime = 0L;
  ::aidl::android::hardware::input::common::Action action = ::aidl::android::hardware::input::common::Action(0);
  int8_t actionIndex = 0;
  ::aidl::android::hardware::input::common::Button actionButton = ::aidl::android::hardware::input::common::Button(0);
  ::aidl::android::hardware::input::common::Flag flags = ::aidl::android::hardware::input::common::Flag(0);
  ::aidl::android::hardware::input::common::PolicyFlag policyFlags = ::aidl::android::hardware::input::common::PolicyFlag(0);
  ::aidl::android::hardware::input::common::EdgeFlag edgeFlags = ::aidl::android::hardware::input::common::EdgeFlag(0);
  ::aidl::android::hardware::input::common::Meta metaState = ::aidl::android::hardware::input::common::Meta(0);
  ::aidl::android::hardware::input::common::Button buttonState = ::aidl::android::hardware::input::common::Button(0);
  float xPrecision = 0.000000f;
  float yPrecision = 0.000000f;
  std::vector<::aidl::android::hardware::input::common::PointerProperties> pointerProperties;
  std::vector<::aidl::android::hardware::input::common::PointerCoords> pointerCoords;
  int32_t deviceTimestamp = 0;
  std::vector<::aidl::android::hardware::input::common::VideoFrame> frames;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator==(const MotionEvent& _rhs) const {
    return std::tie(deviceId, source, displayId, downTime, eventTime, action, actionIndex, actionButton, flags, policyFlags, edgeFlags, metaState, buttonState, xPrecision, yPrecision, pointerProperties, pointerCoords, deviceTimestamp, frames) == std::tie(_rhs.deviceId, _rhs.source, _rhs.displayId, _rhs.downTime, _rhs.eventTime, _rhs.action, _rhs.actionIndex, _rhs.actionButton, _rhs.flags, _rhs.policyFlags, _rhs.edgeFlags, _rhs.metaState, _rhs.buttonState, _rhs.xPrecision, _rhs.yPrecision, _rhs.pointerProperties, _rhs.pointerCoords, _rhs.deviceTimestamp, _rhs.frames);
  }
  inline bool operator<(const MotionEvent& _rhs) const {
    return std::tie(deviceId, source, displayId, downTime, eventTime, action, actionIndex, actionButton, flags, policyFlags, edgeFlags, metaState, buttonState, xPrecision, yPrecision, pointerProperties, pointerCoords, deviceTimestamp, frames) < std::tie(_rhs.deviceId, _rhs.source, _rhs.displayId, _rhs.downTime, _rhs.eventTime, _rhs.action, _rhs.actionIndex, _rhs.actionButton, _rhs.flags, _rhs.policyFlags, _rhs.edgeFlags, _rhs.metaState, _rhs.buttonState, _rhs.xPrecision, _rhs.yPrecision, _rhs.pointerProperties, _rhs.pointerCoords, _rhs.deviceTimestamp, _rhs.frames);
  }
  inline bool operator!=(const MotionEvent& _rhs) const {
    return !(*this == _rhs);
  }
  inline bool operator>(const MotionEvent& _rhs) const {
    return _rhs < *this;
  }
  inline bool operator>=(const MotionEvent& _rhs) const {
    return !(*this < _rhs);
  }
  inline bool operator<=(const MotionEvent& _rhs) const {
    return !(_rhs < *this);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_LOCAL;
  inline std::string toString() const {
    std::ostringstream _aidl_os;
    _aidl_os << "MotionEvent{";
    _aidl_os << "deviceId: " << ::android::internal::ToString(deviceId);
    _aidl_os << ", source: " << ::android::internal::ToString(source);
    _aidl_os << ", displayId: " << ::android::internal::ToString(displayId);
    _aidl_os << ", downTime: " << ::android::internal::ToString(downTime);
    _aidl_os << ", eventTime: " << ::android::internal::ToString(eventTime);
    _aidl_os << ", action: " << ::android::internal::ToString(action);
    _aidl_os << ", actionIndex: " << ::android::internal::ToString(actionIndex);
    _aidl_os << ", actionButton: " << ::android::internal::ToString(actionButton);
    _aidl_os << ", flags: " << ::android::internal::ToString(flags);
    _aidl_os << ", policyFlags: " << ::android::internal::ToString(policyFlags);
    _aidl_os << ", edgeFlags: " << ::android::internal::ToString(edgeFlags);
    _aidl_os << ", metaState: " << ::android::internal::ToString(metaState);
    _aidl_os << ", buttonState: " << ::android::internal::ToString(buttonState);
    _aidl_os << ", xPrecision: " << ::android::internal::ToString(xPrecision);
    _aidl_os << ", yPrecision: " << ::android::internal::ToString(yPrecision);
    _aidl_os << ", pointerProperties: " << ::android::internal::ToString(pointerProperties);
    _aidl_os << ", pointerCoords: " << ::android::internal::ToString(pointerCoords);
    _aidl_os << ", deviceTimestamp: " << ::android::internal::ToString(deviceTimestamp);
    _aidl_os << ", frames: " << ::android::internal::ToString(frames);
    _aidl_os << "}";
    return _aidl_os.str();
  }
};
}  // namespace common
}  // namespace input
}  // namespace hardware
}  // namespace android
}  // namespace aidl
