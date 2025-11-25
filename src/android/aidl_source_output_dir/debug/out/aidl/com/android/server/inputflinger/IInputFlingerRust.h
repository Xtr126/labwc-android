/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl7137759320201058519.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl/com/android/server/inputflinger/IInputFlingerRust.aidl
 */
#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include <android/binder_ibinder.h>
#include <android/binder_interface_utils.h>
#include <aidl/com/android/server/inputflinger/IInputFilter.h>
#include <aidl/com/android/server/inputflinger/IInputFlingerRust.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl::com::android::server::inputflinger {
class IInputFilter;
class IInputFlingerRust;
}  // namespace aidl::com::android::server::inputflinger
namespace aidl {
namespace com {
namespace android {
namespace server {
namespace inputflinger {
class IInputFlingerRustDelegator;

class IInputFlingerRust : public ::ndk::ICInterface {
public:
  typedef IInputFlingerRustDelegator DefaultDelegator;
  static const char* descriptor;
  IInputFlingerRust();
  virtual ~IInputFlingerRust();

  class IInputFlingerRustBootstrapCallbackDelegator;

  class IInputFlingerRustBootstrapCallback : public ::ndk::ICInterface {
  public:
    typedef IInputFlingerRustBootstrapCallbackDelegator DefaultDelegator;
    static const char* descriptor;
    IInputFlingerRustBootstrapCallback();
    virtual ~IInputFlingerRustBootstrapCallback();

    static constexpr uint32_t TRANSACTION_onProvideInputFlingerRust = FIRST_CALL_TRANSACTION + 0;

    static std::shared_ptr<IInputFlingerRustBootstrapCallback> fromBinder(const ::ndk::SpAIBinder& binder);
    static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IInputFlingerRustBootstrapCallback>& instance);
    static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IInputFlingerRustBootstrapCallback>* instance);
    static bool setDefaultImpl(const std::shared_ptr<IInputFlingerRustBootstrapCallback>& impl);
    static const std::shared_ptr<IInputFlingerRustBootstrapCallback>& getDefaultImpl();
    virtual ::ndk::ScopedAStatus onProvideInputFlingerRust(const std::shared_ptr<::aidl::com::android::server::inputflinger::IInputFlingerRust>& in_inputFlingerRust) = 0;
  private:
    static std::shared_ptr<IInputFlingerRustBootstrapCallback> default_impl;
  };
  class IInputFlingerRustBootstrapCallbackDefault : public IInputFlingerRustBootstrapCallback {
  public:
    ::ndk::ScopedAStatus onProvideInputFlingerRust(const std::shared_ptr<::aidl::com::android::server::inputflinger::IInputFlingerRust>& in_inputFlingerRust) override;
    ::ndk::SpAIBinder asBinder() override;
    bool isRemote() override;
  };
  class BpInputFlingerRustBootstrapCallback : public ::ndk::BpCInterface<IInputFlingerRustBootstrapCallback> {
  public:
    explicit BpInputFlingerRustBootstrapCallback(const ::ndk::SpAIBinder& binder);
    virtual ~BpInputFlingerRustBootstrapCallback();

    ::ndk::ScopedAStatus onProvideInputFlingerRust(const std::shared_ptr<::aidl::com::android::server::inputflinger::IInputFlingerRust>& in_inputFlingerRust) override;
  };
  class BnInputFlingerRustBootstrapCallback : public ::ndk::BnCInterface<IInputFlingerRustBootstrapCallback> {
  public:
    BnInputFlingerRustBootstrapCallback();
    virtual ~BnInputFlingerRustBootstrapCallback();
  protected:
    ::ndk::SpAIBinder createBinder() override;
  private:
  };
  static constexpr uint32_t TRANSACTION_createInputFilter = FIRST_CALL_TRANSACTION + 0;

  static std::shared_ptr<IInputFlingerRust> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IInputFlingerRust>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IInputFlingerRust>* instance);
  static bool setDefaultImpl(const std::shared_ptr<IInputFlingerRust>& impl);
  static const std::shared_ptr<IInputFlingerRust>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus createInputFilter(const std::shared_ptr<::aidl::com::android::server::inputflinger::IInputFilter::IInputFilterCallbacks>& in_callbacks, std::shared_ptr<::aidl::com::android::server::inputflinger::IInputFilter>* _aidl_return) = 0;
private:
  static std::shared_ptr<IInputFlingerRust> default_impl;
};
class IInputFlingerRustDefault : public IInputFlingerRust {
public:
  ::ndk::ScopedAStatus createInputFilter(const std::shared_ptr<::aidl::com::android::server::inputflinger::IInputFilter::IInputFilterCallbacks>& in_callbacks, std::shared_ptr<::aidl::com::android::server::inputflinger::IInputFilter>* _aidl_return) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace inputflinger
}  // namespace server
}  // namespace android
}  // namespace com
}  // namespace aidl
