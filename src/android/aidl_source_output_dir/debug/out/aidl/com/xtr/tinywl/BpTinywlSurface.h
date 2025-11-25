/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl4154290964388247707.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl/com/xtr/tinywl/ITinywlSurface.aidl
 */
#pragma once

#include "aidl/com/xtr/tinywl/ITinywlSurface.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace com {
namespace xtr {
namespace tinywl {
class BpTinywlSurface : public ::ndk::BpCInterface<ITinywlSurface> {
public:
  explicit BpTinywlSurface(const ::ndk::SpAIBinder& binder);
  virtual ~BpTinywlSurface();

  ::ndk::ScopedAStatus onSurfaceCreated(const ::aidl::com::xtr::tinywl::XdgTopLevel& in_xdgToplevel) override;
  ::ndk::ScopedAStatus onSurfaceChanged(const ::aidl::com::xtr::tinywl::XdgTopLevel& in_xdgToplevel) override;
  ::ndk::ScopedAStatus onSurfaceDestroyed(const ::aidl::com::xtr::tinywl::XdgTopLevel& in_xdgToplevel) override;
};
}  // namespace tinywl
}  // namespace xtr
}  // namespace com
}  // namespace aidl
