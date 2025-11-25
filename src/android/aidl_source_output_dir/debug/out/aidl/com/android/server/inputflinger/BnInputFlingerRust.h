/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl7137759320201058519.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl/com/android/server/inputflinger/IInputFlingerRust.aidl
 */
#pragma once

#include "aidl/com/android/server/inputflinger/IInputFlingerRust.h"

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
class BnInputFlingerRust : public ::ndk::BnCInterface<IInputFlingerRust> {
public:
  BnInputFlingerRust();
  virtual ~BnInputFlingerRust();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
class IInputFlingerRustDelegator : public BnInputFlingerRust {
public:
  explicit IInputFlingerRustDelegator(const std::shared_ptr<IInputFlingerRust> &impl) : _impl(impl) {
  }

  ::ndk::ScopedAStatus createInputFilter(const std::shared_ptr<::aidl::com::android::server::inputflinger::IInputFilter::IInputFilterCallbacks>& in_callbacks, std::shared_ptr<::aidl::com::android::server::inputflinger::IInputFilter>* _aidl_return) override {
    return _impl->createInputFilter(in_callbacks, _aidl_return);
  }
protected:
private:
  std::shared_ptr<IInputFlingerRust> _impl;
};

}  // namespace inputflinger
}  // namespace server
}  // namespace android
}  // namespace com
}  // namespace aidl
