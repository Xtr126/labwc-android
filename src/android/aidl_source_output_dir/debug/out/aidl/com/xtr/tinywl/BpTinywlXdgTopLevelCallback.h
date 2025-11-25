/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl13715495313705502561.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl/com/xtr/tinywl/TinywlXdgTopLevelCallback.aidl
 */
#pragma once

#include "aidl/com/xtr/tinywl/TinywlXdgTopLevelCallback.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace com {
namespace xtr {
namespace tinywl {
class BpTinywlXdgTopLevelCallback : public ::ndk::BpCInterface<ITinywlXdgTopLevelCallback> {
public:
  explicit BpTinywlXdgTopLevelCallback(const ::ndk::SpAIBinder& binder);
  virtual ~BpTinywlXdgTopLevelCallback();

  ::ndk::ScopedAStatus addXdgTopLevel(const std::string& in_appId, const std::string& in_title, int64_t in_nativePtr, const ::aidl::com::xtr::tinywl::WlrBox& in_geoBox) override;
  ::ndk::ScopedAStatus removeXdgTopLevel(const std::string& in_appId, const std::string& in_title, int64_t in_nativePtr) override;
};
}  // namespace tinywl
}  // namespace xtr
}  // namespace com
}  // namespace aidl
