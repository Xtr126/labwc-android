/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl877169651209726230.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl/tinywl/ITinywlInput.aidl
 */
#pragma once

#include "aidl/tinywl/ITinywlInput.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace tinywl {
class BpTinywlInput : public ::ndk::BpCInterface<ITinywlInput> {
public:
  explicit BpTinywlInput(const ::ndk::SpAIBinder& binder);
  virtual ~BpTinywlInput();

  ::ndk::ScopedAStatus onKeyEvent(const ::aidl::com::android::server::inputflinger::KeyEvent& in_event, int64_t in_nativePtr, bool* _aidl_return) override;
  ::ndk::ScopedAStatus onMotionEvent(const ::aidl::android::hardware::input::common::MotionEvent& in_event, int64_t in_nativePtr, bool* _aidl_return) override;
};
}  // namespace tinywl
}  // namespace aidl
