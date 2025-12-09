/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl12200198985014209377.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl/com/android/server/inputflinger/IInputFilter.aidl
 */
#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include <android/binder_ibinder.h>
#include <android/binder_interface_utils.h>
#include <aidl/com/android/server/inputflinger/DeviceInfo.h>
#include <aidl/com/android/server/inputflinger/IInputThread.h>
#include <aidl/com/android/server/inputflinger/InputFilterConfiguration.h>
#include <aidl/com/android/server/inputflinger/KeyEvent.h>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl::com::android::server::inputflinger {
class DeviceInfo;
class IInputThread;
class InputFilterConfiguration;
class KeyEvent;
}  // namespace aidl::com::android::server::inputflinger
namespace aidl {
namespace com {
namespace android {
namespace server {
namespace inputflinger {
class IInputFilterDelegator;

class IInputFilter : public ::ndk::ICInterface {
public:
  typedef IInputFilterDelegator DefaultDelegator;
  static const char* descriptor;
  IInputFilter();
  virtual ~IInputFilter();

  class IInputFilterCallbacksDelegator;

  class IInputFilterCallbacks : public ::ndk::ICInterface {
  public:
    typedef IInputFilterCallbacksDelegator DefaultDelegator;
    static const char* descriptor;
    IInputFilterCallbacks();
    virtual ~IInputFilterCallbacks();

    static constexpr uint32_t TRANSACTION_sendKeyEvent = FIRST_CALL_TRANSACTION + 0;
    static constexpr uint32_t TRANSACTION_onModifierStateChanged = FIRST_CALL_TRANSACTION + 1;
    static constexpr uint32_t TRANSACTION_createInputFilterThread = FIRST_CALL_TRANSACTION + 2;

    static std::shared_ptr<IInputFilterCallbacks> fromBinder(const ::ndk::SpAIBinder& binder);
    static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IInputFilterCallbacks>& instance);
    static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IInputFilterCallbacks>* instance);
    static bool setDefaultImpl(const std::shared_ptr<IInputFilterCallbacks>& impl);
    static const std::shared_ptr<IInputFilterCallbacks>& getDefaultImpl();
    virtual ::ndk::ScopedAStatus sendKeyEvent(const ::aidl::com::android::server::inputflinger::KeyEvent& in_event) = 0;
    virtual ::ndk::ScopedAStatus onModifierStateChanged(int32_t in_modifierState, int32_t in_lockedModifierState) = 0;
    virtual ::ndk::ScopedAStatus createInputFilterThread(const std::shared_ptr<::aidl::com::android::server::inputflinger::IInputThread::IInputThreadCallback>& in_callback, std::shared_ptr<::aidl::com::android::server::inputflinger::IInputThread>* _aidl_return) = 0;
  private:
    static std::shared_ptr<IInputFilterCallbacks> default_impl;
  };
  class IInputFilterCallbacksDefault : public IInputFilterCallbacks {
  public:
    ::ndk::ScopedAStatus sendKeyEvent(const ::aidl::com::android::server::inputflinger::KeyEvent& in_event) override;
    ::ndk::ScopedAStatus onModifierStateChanged(int32_t in_modifierState, int32_t in_lockedModifierState) override;
    ::ndk::ScopedAStatus createInputFilterThread(const std::shared_ptr<::aidl::com::android::server::inputflinger::IInputThread::IInputThreadCallback>& in_callback, std::shared_ptr<::aidl::com::android::server::inputflinger::IInputThread>* _aidl_return) override;
    ::ndk::SpAIBinder asBinder() override;
    bool isRemote() override;
  };
  class BpInputFilterCallbacks : public ::ndk::BpCInterface<IInputFilterCallbacks> {
  public:
    explicit BpInputFilterCallbacks(const ::ndk::SpAIBinder& binder);
    virtual ~BpInputFilterCallbacks();

    ::ndk::ScopedAStatus sendKeyEvent(const ::aidl::com::android::server::inputflinger::KeyEvent& in_event) override;
    ::ndk::ScopedAStatus onModifierStateChanged(int32_t in_modifierState, int32_t in_lockedModifierState) override;
    ::ndk::ScopedAStatus createInputFilterThread(const std::shared_ptr<::aidl::com::android::server::inputflinger::IInputThread::IInputThreadCallback>& in_callback, std::shared_ptr<::aidl::com::android::server::inputflinger::IInputThread>* _aidl_return) override;
  };
  class BnInputFilterCallbacks : public ::ndk::BnCInterface<IInputFilterCallbacks> {
  public:
    BnInputFilterCallbacks();
    virtual ~BnInputFilterCallbacks();
  protected:
    ::ndk::SpAIBinder createBinder() override;
  private:
  };
  static constexpr uint32_t TRANSACTION_isEnabled = FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_notifyKey = FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_notifyInputDevicesChanged = FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_notifyConfigurationChanged = FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_dumpFilter = FIRST_CALL_TRANSACTION + 4;

  static std::shared_ptr<IInputFilter> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IInputFilter>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IInputFilter>* instance);
  static bool setDefaultImpl(const std::shared_ptr<IInputFilter>& impl);
  static const std::shared_ptr<IInputFilter>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus isEnabled(bool* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus notifyKey(const ::aidl::com::android::server::inputflinger::KeyEvent& in_event) = 0;
  virtual ::ndk::ScopedAStatus notifyInputDevicesChanged(const std::vector<::aidl::com::android::server::inputflinger::DeviceInfo>& in_deviceInfos) = 0;
  virtual ::ndk::ScopedAStatus notifyConfigurationChanged(const ::aidl::com::android::server::inputflinger::InputFilterConfiguration& in_config) = 0;
  virtual ::ndk::ScopedAStatus dumpFilter(std::string* _aidl_return) = 0;
private:
  static std::shared_ptr<IInputFilter> default_impl;
};
class IInputFilterDefault : public IInputFilter {
public:
  ::ndk::ScopedAStatus isEnabled(bool* _aidl_return) override;
  ::ndk::ScopedAStatus notifyKey(const ::aidl::com::android::server::inputflinger::KeyEvent& in_event) override;
  ::ndk::ScopedAStatus notifyInputDevicesChanged(const std::vector<::aidl::com::android::server::inputflinger::DeviceInfo>& in_deviceInfos) override;
  ::ndk::ScopedAStatus notifyConfigurationChanged(const ::aidl::com::android::server::inputflinger::InputFilterConfiguration& in_config) override;
  ::ndk::ScopedAStatus dumpFilter(std::string* _aidl_return) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace inputflinger
}  // namespace server
}  // namespace android
}  // namespace com
}  // namespace aidl
