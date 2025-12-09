/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl877169651209726230.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl/tinywl/ITinywlInput.aidl
 */
#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include <android/binder_interface_utils.h>
#include <aidl/android/hardware/input/common/MotionEvent.h>
#include <aidl/com/android/server/inputflinger/KeyEvent.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl::android::hardware::input::common {
class MotionEvent;
}  // namespace aidl::android::hardware::input::common
namespace aidl::com::android::server::inputflinger {
class KeyEvent;
}  // namespace aidl::com::android::server::inputflinger
namespace aidl {
namespace tinywl {
class ITinywlInputDelegator;

class ITinywlInput : public ::ndk::ICInterface {
public:
  typedef ITinywlInputDelegator DefaultDelegator;
  static const char* descriptor;
  ITinywlInput();
  virtual ~ITinywlInput();

  static constexpr uint32_t TRANSACTION_onKeyEvent = FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_onMotionEvent = FIRST_CALL_TRANSACTION + 1;

  static std::shared_ptr<ITinywlInput> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<ITinywlInput>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<ITinywlInput>* instance);
  static bool setDefaultImpl(const std::shared_ptr<ITinywlInput>& impl);
  static const std::shared_ptr<ITinywlInput>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus onKeyEvent(const ::aidl::com::android::server::inputflinger::KeyEvent& in_event, int64_t in_nativePtr, bool* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus onMotionEvent(const ::aidl::android::hardware::input::common::MotionEvent& in_event, int64_t in_nativePtr, bool* _aidl_return) = 0;
private:
  static std::shared_ptr<ITinywlInput> default_impl;
};
class ITinywlInputDefault : public ITinywlInput {
public:
  ::ndk::ScopedAStatus onKeyEvent(const ::aidl::com::android::server::inputflinger::KeyEvent& in_event, int64_t in_nativePtr, bool* _aidl_return) override;
  ::ndk::ScopedAStatus onMotionEvent(const ::aidl::android::hardware::input::common::MotionEvent& in_event, int64_t in_nativePtr, bool* _aidl_return) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace tinywl
}  // namespace aidl
