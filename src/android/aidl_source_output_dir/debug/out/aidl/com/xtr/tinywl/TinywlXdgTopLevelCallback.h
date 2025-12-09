/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl13715495313705502561.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl/com/xtr/tinywl/TinywlXdgTopLevelCallback.aidl
 */
#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include <android/binder_interface_utils.h>
#include <aidl/com/xtr/tinywl/WlrBox.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl::com::xtr::tinywl {
class WlrBox;
}  // namespace aidl::com::xtr::tinywl
namespace aidl {
namespace com {
namespace xtr {
namespace tinywl {
class ITinywlXdgTopLevelCallbackDelegator;

class ITinywlXdgTopLevelCallback : public ::ndk::ICInterface {
public:
  typedef ITinywlXdgTopLevelCallbackDelegator DefaultDelegator;
  static const char* descriptor;
  ITinywlXdgTopLevelCallback();
  virtual ~ITinywlXdgTopLevelCallback();

  static constexpr uint32_t TRANSACTION_addXdgTopLevel = FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_removeXdgTopLevel = FIRST_CALL_TRANSACTION + 1;

  static std::shared_ptr<ITinywlXdgTopLevelCallback> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<ITinywlXdgTopLevelCallback>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<ITinywlXdgTopLevelCallback>* instance);
  static bool setDefaultImpl(const std::shared_ptr<ITinywlXdgTopLevelCallback>& impl);
  static const std::shared_ptr<ITinywlXdgTopLevelCallback>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus addXdgTopLevel(const std::string& in_appId, const std::string& in_title, int64_t in_nativePtr, const ::aidl::com::xtr::tinywl::WlrBox& in_geoBox) = 0;
  virtual ::ndk::ScopedAStatus removeXdgTopLevel(const std::string& in_appId, const std::string& in_title, int64_t in_nativePtr) = 0;
private:
  static std::shared_ptr<ITinywlXdgTopLevelCallback> default_impl;
};
class ITinywlXdgTopLevelCallbackDefault : public ITinywlXdgTopLevelCallback {
public:
  ::ndk::ScopedAStatus addXdgTopLevel(const std::string& in_appId, const std::string& in_title, int64_t in_nativePtr, const ::aidl::com::xtr::tinywl::WlrBox& in_geoBox) override;
  ::ndk::ScopedAStatus removeXdgTopLevel(const std::string& in_appId, const std::string& in_title, int64_t in_nativePtr) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace tinywl
}  // namespace xtr
}  // namespace com
}  // namespace aidl
