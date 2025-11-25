/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl10612235381581850503.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl/com/android/server/inputflinger/IInputThread.aidl
 */
#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include <android/binder_ibinder.h>
#include <android/binder_interface_utils.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl {
namespace com {
namespace android {
namespace server {
namespace inputflinger {
class IInputThreadDelegator;

class IInputThread : public ::ndk::ICInterface {
public:
  typedef IInputThreadDelegator DefaultDelegator;
  static const char* descriptor;
  IInputThread();
  virtual ~IInputThread();

  class IInputThreadCallbackDelegator;

  class IInputThreadCallback : public ::ndk::ICInterface {
  public:
    typedef IInputThreadCallbackDelegator DefaultDelegator;
    static const char* descriptor;
    IInputThreadCallback();
    virtual ~IInputThreadCallback();

    static constexpr uint32_t TRANSACTION_loopOnce = FIRST_CALL_TRANSACTION + 0;

    static std::shared_ptr<IInputThreadCallback> fromBinder(const ::ndk::SpAIBinder& binder);
    static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IInputThreadCallback>& instance);
    static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IInputThreadCallback>* instance);
    static bool setDefaultImpl(const std::shared_ptr<IInputThreadCallback>& impl);
    static const std::shared_ptr<IInputThreadCallback>& getDefaultImpl();
    virtual ::ndk::ScopedAStatus loopOnce() = 0;
  private:
    static std::shared_ptr<IInputThreadCallback> default_impl;
  };
  class IInputThreadCallbackDefault : public IInputThreadCallback {
  public:
    ::ndk::ScopedAStatus loopOnce() override;
    ::ndk::SpAIBinder asBinder() override;
    bool isRemote() override;
  };
  class BpInputThreadCallback : public ::ndk::BpCInterface<IInputThreadCallback> {
  public:
    explicit BpInputThreadCallback(const ::ndk::SpAIBinder& binder);
    virtual ~BpInputThreadCallback();

    ::ndk::ScopedAStatus loopOnce() override;
  };
  class BnInputThreadCallback : public ::ndk::BnCInterface<IInputThreadCallback> {
  public:
    BnInputThreadCallback();
    virtual ~BnInputThreadCallback();
  protected:
    ::ndk::SpAIBinder createBinder() override;
  private:
  };
  static constexpr uint32_t TRANSACTION_finish = FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_wake = FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_sleepUntil = FIRST_CALL_TRANSACTION + 2;

  static std::shared_ptr<IInputThread> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IInputThread>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IInputThread>* instance);
  static bool setDefaultImpl(const std::shared_ptr<IInputThread>& impl);
  static const std::shared_ptr<IInputThread>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus finish() = 0;
  virtual ::ndk::ScopedAStatus wake() = 0;
  virtual ::ndk::ScopedAStatus sleepUntil(int64_t in_whenNanos) = 0;
private:
  static std::shared_ptr<IInputThread> default_impl;
};
class IInputThreadDefault : public IInputThread {
public:
  ::ndk::ScopedAStatus finish() override;
  ::ndk::ScopedAStatus wake() override;
  ::ndk::ScopedAStatus sleepUntil(int64_t in_whenNanos) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace inputflinger
}  // namespace server
}  // namespace android
}  // namespace com
}  // namespace aidl
