/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl12200198985014209377.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl/com/android/server/inputflinger/IInputFilter.aidl
 */
#include "aidl/com/android/server/inputflinger/IInputFilter.h"

#include <android/binder_parcel_utils.h>
#include <aidl/com/android/server/inputflinger/BnInputFilter.h>
#include <aidl/com/android/server/inputflinger/BnInputThread.h>
#include <aidl/com/android/server/inputflinger/BpInputFilter.h>
#include <aidl/com/android/server/inputflinger/BpInputThread.h>
#include <aidl/com/android/server/inputflinger/IInputThread.h>

namespace aidl {
namespace com {
namespace android {
namespace server {
namespace inputflinger {
static binder_status_t _aidl_com_android_server_inputflinger_IInputFilter_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnInputFilter> _aidl_impl = std::static_pointer_cast<BnInputFilter>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*isEnabled*/): {
      bool _aidl_return;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->isEnabled(&_aidl_return);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = ::ndk::AParcel_writeData(_aidl_out, _aidl_return);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 1 /*notifyKey*/): {
      ::aidl::com::android::server::inputflinger::KeyEvent in_event;

      _aidl_ret_status = ::ndk::AParcel_readData(_aidl_in, &in_event);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->notifyKey(in_event);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 2 /*notifyInputDevicesChanged*/): {
      std::vector<::aidl::com::android::server::inputflinger::DeviceInfo> in_deviceInfos;

      _aidl_ret_status = ::ndk::AParcel_readData(_aidl_in, &in_deviceInfos);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->notifyInputDevicesChanged(in_deviceInfos);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 3 /*notifyConfigurationChanged*/): {
      ::aidl::com::android::server::inputflinger::InputFilterConfiguration in_config;

      _aidl_ret_status = ::ndk::AParcel_readData(_aidl_in, &in_config);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->notifyConfigurationChanged(in_config);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 4 /*dumpFilter*/): {
      std::string _aidl_return;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->dumpFilter(&_aidl_return);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = ::ndk::AParcel_writeData(_aidl_out, _aidl_return);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
  }
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_com_android_server_inputflinger_IInputFilter_clazz = ::ndk::ICInterface::defineClass(IInputFilter::descriptor, _aidl_com_android_server_inputflinger_IInputFilter_onTransact);

BpInputFilter::BpInputFilter(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpInputFilter::~BpInputFilter() {}

::ndk::ScopedAStatus BpInputFilter::isEnabled(bool* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*isEnabled*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IInputFilter::getDefaultImpl()) {
    _aidl_status = IInputFilter::getDefaultImpl()->isEnabled(_aidl_return);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_ret_status = ::ndk::AParcel_readData(_aidl_out.get(), _aidl_return);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpInputFilter::notifyKey(const ::aidl::com::android::server::inputflinger::KeyEvent& in_event) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeData(_aidl_in.get(), in_event);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 1 /*notifyKey*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IInputFilter::getDefaultImpl()) {
    _aidl_status = IInputFilter::getDefaultImpl()->notifyKey(in_event);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpInputFilter::notifyInputDevicesChanged(const std::vector<::aidl::com::android::server::inputflinger::DeviceInfo>& in_deviceInfos) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeData(_aidl_in.get(), in_deviceInfos);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 2 /*notifyInputDevicesChanged*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IInputFilter::getDefaultImpl()) {
    _aidl_status = IInputFilter::getDefaultImpl()->notifyInputDevicesChanged(in_deviceInfos);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpInputFilter::notifyConfigurationChanged(const ::aidl::com::android::server::inputflinger::InputFilterConfiguration& in_config) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeData(_aidl_in.get(), in_config);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 3 /*notifyConfigurationChanged*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IInputFilter::getDefaultImpl()) {
    _aidl_status = IInputFilter::getDefaultImpl()->notifyConfigurationChanged(in_config);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpInputFilter::dumpFilter(std::string* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 4 /*dumpFilter*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IInputFilter::getDefaultImpl()) {
    _aidl_status = IInputFilter::getDefaultImpl()->dumpFilter(_aidl_return);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_ret_status = ::ndk::AParcel_readData(_aidl_out.get(), _aidl_return);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
// Source for BnInputFilter
BnInputFilter::BnInputFilter() {}
BnInputFilter::~BnInputFilter() {}
::ndk::SpAIBinder BnInputFilter::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_com_android_server_inputflinger_IInputFilter_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for IInputFilter
const char* IInputFilter::descriptor = "com.android.server.inputflinger.IInputFilter";
IInputFilter::IInputFilter() {}
IInputFilter::~IInputFilter() {}


std::shared_ptr<IInputFilter> IInputFilter::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_com_android_server_inputflinger_IInputFilter_clazz)) {
    #if __ANDROID_API__ >= 31
    const AIBinder_Class* originalClass = AIBinder_getClass(binder.get());
    if (originalClass == nullptr) return nullptr;
    if (0 == strcmp(AIBinder_Class_getDescriptor(originalClass), descriptor)) {
      return ::ndk::SharedRefBase::make<BpInputFilter>(binder);
    }
    #endif
    return nullptr;
  }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<IInputFilter>(interface);
  }
  return ::ndk::SharedRefBase::make<BpInputFilter>(binder);
}

binder_status_t IInputFilter::writeToParcel(AParcel* parcel, const std::shared_ptr<IInputFilter>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t IInputFilter::readFromParcel(const AParcel* parcel, std::shared_ptr<IInputFilter>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = IInputFilter::fromBinder(binder);
  return STATUS_OK;
}
bool IInputFilter::setDefaultImpl(const std::shared_ptr<IInputFilter>& impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!IInputFilter::default_impl);
  if (impl) {
    IInputFilter::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<IInputFilter>& IInputFilter::getDefaultImpl() {
  return IInputFilter::default_impl;
}
std::shared_ptr<IInputFilter> IInputFilter::default_impl = nullptr;
::ndk::ScopedAStatus IInputFilterDefault::isEnabled(bool* /*_aidl_return*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IInputFilterDefault::notifyKey(const ::aidl::com::android::server::inputflinger::KeyEvent& /*in_event*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IInputFilterDefault::notifyInputDevicesChanged(const std::vector<::aidl::com::android::server::inputflinger::DeviceInfo>& /*in_deviceInfos*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IInputFilterDefault::notifyConfigurationChanged(const ::aidl::com::android::server::inputflinger::InputFilterConfiguration& /*in_config*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IInputFilterDefault::dumpFilter(std::string* /*_aidl_return*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder IInputFilterDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool IInputFilterDefault::isRemote() {
  return false;
}
}  // namespace inputflinger
}  // namespace server
}  // namespace android
}  // namespace com
}  // namespace aidl
namespace aidl {
namespace com {
namespace android {
namespace server {
namespace inputflinger {
static binder_status_t _aidl_com_android_server_inputflinger_IInputFilter_IInputFilterCallbacks_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<IInputFilter::BnInputFilterCallbacks> _aidl_impl = std::static_pointer_cast<IInputFilter::BnInputFilterCallbacks>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*sendKeyEvent*/): {
      ::aidl::com::android::server::inputflinger::KeyEvent in_event;

      _aidl_ret_status = ::ndk::AParcel_readData(_aidl_in, &in_event);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->sendKeyEvent(in_event);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 1 /*onModifierStateChanged*/): {
      int32_t in_modifierState;
      int32_t in_lockedModifierState;

      _aidl_ret_status = ::ndk::AParcel_readData(_aidl_in, &in_modifierState);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readData(_aidl_in, &in_lockedModifierState);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->onModifierStateChanged(in_modifierState, in_lockedModifierState);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 2 /*createInputFilterThread*/): {
      std::shared_ptr<::aidl::com::android::server::inputflinger::IInputThread::IInputThreadCallback> in_callback;
      std::shared_ptr<::aidl::com::android::server::inputflinger::IInputThread> _aidl_return;

      _aidl_ret_status = ::ndk::AParcel_readData(_aidl_in, &in_callback);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->createInputFilterThread(in_callback, &_aidl_return);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = ::ndk::AParcel_writeData(_aidl_out, _aidl_return);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
  }
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_com_android_server_inputflinger_IInputFilter_IInputFilterCallbacks_clazz = ::ndk::ICInterface::defineClass(IInputFilter::IInputFilterCallbacks::descriptor, _aidl_com_android_server_inputflinger_IInputFilter_IInputFilterCallbacks_onTransact);

IInputFilter::BpInputFilterCallbacks::BpInputFilterCallbacks(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
IInputFilter::BpInputFilterCallbacks::~BpInputFilterCallbacks() {}

::ndk::ScopedAStatus IInputFilter::BpInputFilterCallbacks::sendKeyEvent(const ::aidl::com::android::server::inputflinger::KeyEvent& in_event) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeData(_aidl_in.get(), in_event);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*sendKeyEvent*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IInputFilterCallbacks::getDefaultImpl()) {
    _aidl_status = IInputFilterCallbacks::getDefaultImpl()->sendKeyEvent(in_event);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus IInputFilter::BpInputFilterCallbacks::onModifierStateChanged(int32_t in_modifierState, int32_t in_lockedModifierState) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeData(_aidl_in.get(), in_modifierState);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeData(_aidl_in.get(), in_lockedModifierState);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 1 /*onModifierStateChanged*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IInputFilterCallbacks::getDefaultImpl()) {
    _aidl_status = IInputFilterCallbacks::getDefaultImpl()->onModifierStateChanged(in_modifierState, in_lockedModifierState);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus IInputFilter::BpInputFilterCallbacks::createInputFilterThread(const std::shared_ptr<::aidl::com::android::server::inputflinger::IInputThread::IInputThreadCallback>& in_callback, std::shared_ptr<::aidl::com::android::server::inputflinger::IInputThread>* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeData(_aidl_in.get(), in_callback);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 2 /*createInputFilterThread*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IInputFilterCallbacks::getDefaultImpl()) {
    _aidl_status = IInputFilterCallbacks::getDefaultImpl()->createInputFilterThread(in_callback, _aidl_return);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_ret_status = ::ndk::AParcel_readData(_aidl_out.get(), _aidl_return);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
// Source for BnInputFilterCallbacks
IInputFilter::BnInputFilterCallbacks::BnInputFilterCallbacks() {}
IInputFilter::BnInputFilterCallbacks::~BnInputFilterCallbacks() {}
::ndk::SpAIBinder IInputFilter::BnInputFilterCallbacks::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_com_android_server_inputflinger_IInputFilter_IInputFilterCallbacks_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for IInputFilterCallbacks
const char* IInputFilter::IInputFilterCallbacks::descriptor = "com.android.server.inputflinger.IInputFilter.IInputFilterCallbacks";
IInputFilter::IInputFilterCallbacks::IInputFilterCallbacks() {}
IInputFilter::IInputFilterCallbacks::~IInputFilterCallbacks() {}


std::shared_ptr<IInputFilter::IInputFilterCallbacks> IInputFilter::IInputFilterCallbacks::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_com_android_server_inputflinger_IInputFilter_IInputFilterCallbacks_clazz)) {
    #if __ANDROID_API__ >= 31
    const AIBinder_Class* originalClass = AIBinder_getClass(binder.get());
    if (originalClass == nullptr) return nullptr;
    if (0 == strcmp(AIBinder_Class_getDescriptor(originalClass), descriptor)) {
      return ::ndk::SharedRefBase::make<IInputFilter::BpInputFilterCallbacks>(binder);
    }
    #endif
    return nullptr;
  }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<IInputFilterCallbacks>(interface);
  }
  return ::ndk::SharedRefBase::make<IInputFilter::BpInputFilterCallbacks>(binder);
}

binder_status_t IInputFilter::IInputFilterCallbacks::writeToParcel(AParcel* parcel, const std::shared_ptr<IInputFilterCallbacks>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t IInputFilter::IInputFilterCallbacks::readFromParcel(const AParcel* parcel, std::shared_ptr<IInputFilterCallbacks>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = IInputFilterCallbacks::fromBinder(binder);
  return STATUS_OK;
}
bool IInputFilter::IInputFilterCallbacks::setDefaultImpl(const std::shared_ptr<IInputFilterCallbacks>& impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!IInputFilterCallbacks::default_impl);
  if (impl) {
    IInputFilterCallbacks::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<IInputFilter::IInputFilterCallbacks>& IInputFilter::IInputFilterCallbacks::getDefaultImpl() {
  return IInputFilterCallbacks::default_impl;
}
std::shared_ptr<IInputFilter::IInputFilterCallbacks> IInputFilter::IInputFilterCallbacks::default_impl = nullptr;
::ndk::ScopedAStatus IInputFilter::IInputFilterCallbacksDefault::sendKeyEvent(const ::aidl::com::android::server::inputflinger::KeyEvent& /*in_event*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IInputFilter::IInputFilterCallbacksDefault::onModifierStateChanged(int32_t /*in_modifierState*/, int32_t /*in_lockedModifierState*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IInputFilter::IInputFilterCallbacksDefault::createInputFilterThread(const std::shared_ptr<::aidl::com::android::server::inputflinger::IInputThread::IInputThreadCallback>& /*in_callback*/, std::shared_ptr<::aidl::com::android::server::inputflinger::IInputThread>* /*_aidl_return*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder IInputFilter::IInputFilterCallbacksDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool IInputFilter::IInputFilterCallbacksDefault::isRemote() {
  return false;
}
}  // namespace inputflinger
}  // namespace server
}  // namespace android
}  // namespace com
}  // namespace aidl
