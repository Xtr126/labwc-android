/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl2453284031907475535.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl/com/xtr/tinywl/ITinywlMain.aidl
 */
#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include <android/binder_interface_utils.h>
#include <aidl/com/xtr/tinywl/TinywlXdgTopLevelCallback.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl::com::xtr::tinywl {
class ITinywlXdgTopLevelCallback;
}  // namespace aidl::com::xtr::tinywl
namespace aidl {
namespace com {
namespace xtr {
namespace tinywl {
class ITinywlMainDelegator;

class ITinywlMain : public ::ndk::ICInterface {
public:
  typedef ITinywlMainDelegator DefaultDelegator;
  static const char* descriptor;
  ITinywlMain();
  virtual ~ITinywlMain();

  static constexpr uint32_t TRANSACTION_registerXdgTopLevelCallback = FIRST_CALL_TRANSACTION + 0;

  static std::shared_ptr<ITinywlMain> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<ITinywlMain>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<ITinywlMain>* instance);
  static bool setDefaultImpl(const std::shared_ptr<ITinywlMain>& impl);
  static const std::shared_ptr<ITinywlMain>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus registerXdgTopLevelCallback(const std::shared_ptr<::aidl::com::xtr::tinywl::ITinywlXdgTopLevelCallback>& in_xdgTopLevelCallback) = 0;
private:
  static std::shared_ptr<ITinywlMain> default_impl;
};
class ITinywlMainDefault : public ITinywlMain {
public:
  ::ndk::ScopedAStatus registerXdgTopLevelCallback(const std::shared_ptr<::aidl::com::xtr::tinywl::ITinywlXdgTopLevelCallback>& in_xdgTopLevelCallback) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace tinywl
}  // namespace xtr
}  // namespace com
}  // namespace aidl
