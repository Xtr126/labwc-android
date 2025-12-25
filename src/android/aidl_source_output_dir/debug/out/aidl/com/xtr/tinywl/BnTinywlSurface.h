/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl6268573902068650385.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl/com/xtr/tinywl/ITinywlSurface.aidl
 */
#pragma once

#include "aidl/com/xtr/tinywl/ITinywlSurface.h"

#include <android/binder_ibinder.h>
#include <cassert>

#ifndef __BIONIC__
#ifndef __assert2
#define __assert2(a,b,c,d) ((void)0)
#endif
#endif

namespace aidl {
namespace com {
namespace xtr {
namespace tinywl {
class BnTinywlSurface : public ::ndk::BnCInterface<ITinywlSurface> {
public:
  BnTinywlSurface();
  virtual ~BnTinywlSurface();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
class ITinywlSurfaceDelegator : public BnTinywlSurface {
public:
  explicit ITinywlSurfaceDelegator(const std::shared_ptr<ITinywlSurface> &impl) : _impl(impl) {
  }

  ::ndk::ScopedAStatus onSurfaceCreated(int64_t in_nativePtr, ::aidl::com::xtr::tinywl::NativePtrType in_nativePtrType, const ::aidl::android::view::Surface& in_surface) override {
    return _impl->onSurfaceCreated(in_nativePtr, in_nativePtrType, in_surface);
  }
  ::ndk::ScopedAStatus onSurfaceChanged(int64_t in_nativePtr, ::aidl::com::xtr::tinywl::NativePtrType in_nativePtrType, const ::aidl::android::view::Surface& in_surface) override {
    return _impl->onSurfaceChanged(in_nativePtr, in_nativePtrType, in_surface);
  }
  ::ndk::ScopedAStatus onSurfaceDestroyed(int64_t in_nativePtr, ::aidl::com::xtr::tinywl::NativePtrType in_nativePtrType) override {
    return _impl->onSurfaceDestroyed(in_nativePtr, in_nativePtrType);
  }
protected:
private:
  std::shared_ptr<ITinywlSurface> _impl;
};

}  // namespace tinywl
}  // namespace xtr
}  // namespace com
}  // namespace aidl
