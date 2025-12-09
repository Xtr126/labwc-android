/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl10612235381581850503.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl/com/android/server/inputflinger/IInputThread.aidl
 */
#pragma once

#include "aidl/com/android/server/inputflinger/IInputThread.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace com {
namespace android {
namespace server {
namespace inputflinger {
class BpInputThread : public ::ndk::BpCInterface<IInputThread> {
public:
  explicit BpInputThread(const ::ndk::SpAIBinder& binder);
  virtual ~BpInputThread();

  ::ndk::ScopedAStatus finish() override;
  ::ndk::ScopedAStatus wake() override;
  ::ndk::ScopedAStatus sleepUntil(int64_t in_whenNanos) override;
};
}  // namespace inputflinger
}  // namespace server
}  // namespace android
}  // namespace com
}  // namespace aidl
