/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl12200198985014209377.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl/com/android/server/inputflinger/IInputFilter.aidl
 */
#pragma once

#include "aidl/com/android/server/inputflinger/IInputFilter.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace com {
namespace android {
namespace server {
namespace inputflinger {
class BpInputFilter : public ::ndk::BpCInterface<IInputFilter> {
public:
  explicit BpInputFilter(const ::ndk::SpAIBinder& binder);
  virtual ~BpInputFilter();

  ::ndk::ScopedAStatus isEnabled(bool* _aidl_return) override;
  ::ndk::ScopedAStatus notifyKey(const ::aidl::com::android::server::inputflinger::KeyEvent& in_event) override;
  ::ndk::ScopedAStatus notifyInputDevicesChanged(const std::vector<::aidl::com::android::server::inputflinger::DeviceInfo>& in_deviceInfos) override;
  ::ndk::ScopedAStatus notifyConfigurationChanged(const ::aidl::com::android::server::inputflinger::InputFilterConfiguration& in_config) override;
  ::ndk::ScopedAStatus dumpFilter(std::string* _aidl_return) override;
};
}  // namespace inputflinger
}  // namespace server
}  // namespace android
}  // namespace com
}  // namespace aidl
