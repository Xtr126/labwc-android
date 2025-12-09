/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl10612235381581850503.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl/com/android/server/inputflinger/IInputThread.aidl
 */
#pragma once

#include "aidl/com/android/server/inputflinger/IInputThread.h"

#include <android/binder_ibinder.h>
#include <cassert>

#ifndef __BIONIC__
#ifndef __assert2
#define __assert2(a,b,c,d) ((void)0)
#endif
#endif

namespace aidl {
namespace com {
namespace android {
namespace server {
namespace inputflinger {
class BnInputThread : public ::ndk::BnCInterface<IInputThread> {
public:
  BnInputThread();
  virtual ~BnInputThread();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
class IInputThreadDelegator : public BnInputThread {
public:
  explicit IInputThreadDelegator(const std::shared_ptr<IInputThread> &impl) : _impl(impl) {
  }

  ::ndk::ScopedAStatus finish() override {
    return _impl->finish();
  }
  ::ndk::ScopedAStatus wake() override {
    return _impl->wake();
  }
  ::ndk::ScopedAStatus sleepUntil(int64_t in_whenNanos) override {
    return _impl->sleepUntil(in_whenNanos);
  }
protected:
private:
  std::shared_ptr<IInputThread> _impl;
};

}  // namespace inputflinger
}  // namespace server
}  // namespace android
}  // namespace com
}  // namespace aidl
