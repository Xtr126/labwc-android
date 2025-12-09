/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl877169651209726230.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl/tinywl/ITinywlInput.aidl
 */
#pragma once

#include "aidl/tinywl/ITinywlInput.h"

#include <android/binder_ibinder.h>
#include <cassert>

#ifndef __BIONIC__
#ifndef __assert2
#define __assert2(a,b,c,d) ((void)0)
#endif
#endif

namespace aidl {
namespace tinywl {
class BnTinywlInput : public ::ndk::BnCInterface<ITinywlInput> {
public:
  BnTinywlInput();
  virtual ~BnTinywlInput();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
class ITinywlInputDelegator : public BnTinywlInput {
public:
  explicit ITinywlInputDelegator(const std::shared_ptr<ITinywlInput> &impl) : _impl(impl) {
  }

  ::ndk::ScopedAStatus onKeyEvent(const ::aidl::com::android::server::inputflinger::KeyEvent& in_event, int64_t in_nativePtr, bool* _aidl_return) override {
    return _impl->onKeyEvent(in_event, in_nativePtr, _aidl_return);
  }
  ::ndk::ScopedAStatus onMotionEvent(const ::aidl::android::hardware::input::common::MotionEvent& in_event, int64_t in_nativePtr, bool* _aidl_return) override {
    return _impl->onMotionEvent(in_event, in_nativePtr, _aidl_return);
  }
protected:
private:
  std::shared_ptr<ITinywlInput> _impl;
};

}  // namespace tinywl
}  // namespace aidl
