/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl12200198985014209377.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl/com/android/server/inputflinger/IInputFilter.aidl
 */
#pragma once

#include "aidl/com/android/server/inputflinger/IInputFilter.h"

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
class BnInputFilter : public ::ndk::BnCInterface<IInputFilter> {
public:
  BnInputFilter();
  virtual ~BnInputFilter();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
class IInputFilterDelegator : public BnInputFilter {
public:
  explicit IInputFilterDelegator(const std::shared_ptr<IInputFilter> &impl) : _impl(impl) {
  }

  ::ndk::ScopedAStatus isEnabled(bool* _aidl_return) override {
    return _impl->isEnabled(_aidl_return);
  }
  ::ndk::ScopedAStatus notifyKey(const ::aidl::com::android::server::inputflinger::KeyEvent& in_event) override {
    return _impl->notifyKey(in_event);
  }
  ::ndk::ScopedAStatus notifyInputDevicesChanged(const std::vector<::aidl::com::android::server::inputflinger::DeviceInfo>& in_deviceInfos) override {
    return _impl->notifyInputDevicesChanged(in_deviceInfos);
  }
  ::ndk::ScopedAStatus notifyConfigurationChanged(const ::aidl::com::android::server::inputflinger::InputFilterConfiguration& in_config) override {
    return _impl->notifyConfigurationChanged(in_config);
  }
  ::ndk::ScopedAStatus dumpFilter(std::string* _aidl_return) override {
    return _impl->dumpFilter(_aidl_return);
  }
protected:
private:
  std::shared_ptr<IInputFilter> _impl;
};

}  // namespace inputflinger
}  // namespace server
}  // namespace android
}  // namespace com
}  // namespace aidl
