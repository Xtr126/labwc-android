/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl2453284031907475535.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl/com/xtr/tinywl/ITinywlMain.aidl
 */
#pragma once

#include "aidl/com/xtr/tinywl/ITinywlMain.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace com {
namespace xtr {
namespace tinywl {
class BpTinywlMain : public ::ndk::BpCInterface<ITinywlMain> {
public:
  explicit BpTinywlMain(const ::ndk::SpAIBinder& binder);
  virtual ~BpTinywlMain();

  ::ndk::ScopedAStatus registerXdgTopLevelCallback(const std::shared_ptr<::aidl::com::xtr::tinywl::ITinywlXdgTopLevelCallback>& in_xdgTopLevelCallback) override;
};
}  // namespace tinywl
}  // namespace xtr
}  // namespace com
}  // namespace aidl
