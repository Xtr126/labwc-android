/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl4154290964388247707.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl/com/xtr/tinywl/ITinywlSurface.aidl
 */
#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include <android/binder_interface_utils.h>
#include <aidl/com/xtr/tinywl/XdgTopLevel.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl::com::xtr::tinywl {
class XdgTopLevel;
}  // namespace aidl::com::xtr::tinywl
namespace aidl {
namespace com {
namespace xtr {
namespace tinywl {
class ITinywlSurfaceDelegator;

class ITinywlSurface : public ::ndk::ICInterface {
public:
  typedef ITinywlSurfaceDelegator DefaultDelegator;
  static const char* descriptor;
  ITinywlSurface();
  virtual ~ITinywlSurface();

  static constexpr uint32_t TRANSACTION_onSurfaceCreated = FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_onSurfaceChanged = FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_onSurfaceDestroyed = FIRST_CALL_TRANSACTION + 2;

  static std::shared_ptr<ITinywlSurface> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<ITinywlSurface>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<ITinywlSurface>* instance);
  static bool setDefaultImpl(const std::shared_ptr<ITinywlSurface>& impl);
  static const std::shared_ptr<ITinywlSurface>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus onSurfaceCreated(const ::aidl::com::xtr::tinywl::XdgTopLevel& in_xdgToplevel) = 0;
  virtual ::ndk::ScopedAStatus onSurfaceChanged(const ::aidl::com::xtr::tinywl::XdgTopLevel& in_xdgToplevel) = 0;
  virtual ::ndk::ScopedAStatus onSurfaceDestroyed(const ::aidl::com::xtr::tinywl::XdgTopLevel& in_xdgToplevel) = 0;
private:
  static std::shared_ptr<ITinywlSurface> default_impl;
};
class ITinywlSurfaceDefault : public ITinywlSurface {
public:
  ::ndk::ScopedAStatus onSurfaceCreated(const ::aidl::com::xtr::tinywl::XdgTopLevel& in_xdgToplevel) override;
  ::ndk::ScopedAStatus onSurfaceChanged(const ::aidl::com::xtr::tinywl::XdgTopLevel& in_xdgToplevel) override;
  ::ndk::ScopedAStatus onSurfaceDestroyed(const ::aidl::com::xtr::tinywl::XdgTopLevel& in_xdgToplevel) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace tinywl
}  // namespace xtr
}  // namespace com
}  // namespace aidl
