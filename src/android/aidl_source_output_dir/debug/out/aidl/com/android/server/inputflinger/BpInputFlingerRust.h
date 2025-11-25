/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl7137759320201058519.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl/com/android/server/inputflinger/IInputFlingerRust.aidl
 */
#pragma once

#include "aidl/com/android/server/inputflinger/IInputFlingerRust.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace com {
namespace android {
namespace server {
namespace inputflinger {
class BpInputFlingerRust : public ::ndk::BpCInterface<IInputFlingerRust> {
public:
  explicit BpInputFlingerRust(const ::ndk::SpAIBinder& binder);
  virtual ~BpInputFlingerRust();

  ::ndk::ScopedAStatus createInputFilter(const std::shared_ptr<::aidl::com::android::server::inputflinger::IInputFilter::IInputFilterCallbacks>& in_callbacks, std::shared_ptr<::aidl::com::android::server::inputflinger::IInputFilter>* _aidl_return) override;
};
}  // namespace inputflinger
}  // namespace server
}  // namespace android
}  // namespace com
}  // namespace aidl
