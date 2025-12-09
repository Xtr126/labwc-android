/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl7137759320201058519.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl/com/android/server/inputflinger/IInputFlingerRust.aidl
 */
#include "aidl/com/android/server/inputflinger/IInputFlingerRust.h"

#include <android/binder_parcel_utils.h>
#include <aidl/com/android/server/inputflinger/BnInputFilter.h>
#include <aidl/com/android/server/inputflinger/BnInputFlingerRust.h>
#include <aidl/com/android/server/inputflinger/BnInputThread.h>
#include <aidl/com/android/server/inputflinger/BpInputFilter.h>
#include <aidl/com/android/server/inputflinger/BpInputFlingerRust.h>
#include <aidl/com/android/server/inputflinger/BpInputThread.h>
#include <aidl/com/android/server/inputflinger/IInputFilter.h>
#include <aidl/com/android/server/inputflinger/IInputThread.h>

namespace aidl {
namespace com {
namespace android {
namespace server {
namespace inputflinger {
static binder_status_t _aidl_com_android_server_inputflinger_IInputFlingerRust_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnInputFlingerRust> _aidl_impl = std::static_pointer_cast<BnInputFlingerRust>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*createInputFilter*/): {
      std::shared_ptr<::aidl::com::android::server::inputflinger::IInputFilter::IInputFilterCallbacks> in_callbacks;
      std::shared_ptr<::aidl::com::android::server::inputflinger::IInputFilter> _aidl_return;

      _aidl_ret_status = ::ndk::AParcel_readData(_aidl_in, &in_callbacks);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->createInputFilter(in_callbacks, &_aidl_return);
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

static AIBinder_Class* _g_aidl_com_android_server_inputflinger_IInputFlingerRust_clazz = ::ndk::ICInterface::defineClass(IInputFlingerRust::descriptor, _aidl_com_android_server_inputflinger_IInputFlingerRust_onTransact);

BpInputFlingerRust::BpInputFlingerRust(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpInputFlingerRust::~BpInputFlingerRust() {}

::ndk::ScopedAStatus BpInputFlingerRust::createInputFilter(const std::shared_ptr<::aidl::com::android::server::inputflinger::IInputFilter::IInputFilterCallbacks>& in_callbacks, std::shared_ptr<::aidl::com::android::server::inputflinger::IInputFilter>* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeData(_aidl_in.get(), in_callbacks);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*createInputFilter*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IInputFlingerRust::getDefaultImpl()) {
    _aidl_status = IInputFlingerRust::getDefaultImpl()->createInputFilter(in_callbacks, _aidl_return);
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
// Source for BnInputFlingerRust
BnInputFlingerRust::BnInputFlingerRust() {}
BnInputFlingerRust::~BnInputFlingerRust() {}
::ndk::SpAIBinder BnInputFlingerRust::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_com_android_server_inputflinger_IInputFlingerRust_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for IInputFlingerRust
const char* IInputFlingerRust::descriptor = "com.android.server.inputflinger.IInputFlingerRust";
IInputFlingerRust::IInputFlingerRust() {}
IInputFlingerRust::~IInputFlingerRust() {}


std::shared_ptr<IInputFlingerRust> IInputFlingerRust::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_com_android_server_inputflinger_IInputFlingerRust_clazz)) {
    #if __ANDROID_API__ >= 31
    const AIBinder_Class* originalClass = AIBinder_getClass(binder.get());
    if (originalClass == nullptr) return nullptr;
    if (0 == strcmp(AIBinder_Class_getDescriptor(originalClass), descriptor)) {
      return ::ndk::SharedRefBase::make<BpInputFlingerRust>(binder);
    }
    #endif
    return nullptr;
  }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<IInputFlingerRust>(interface);
  }
  return ::ndk::SharedRefBase::make<BpInputFlingerRust>(binder);
}

binder_status_t IInputFlingerRust::writeToParcel(AParcel* parcel, const std::shared_ptr<IInputFlingerRust>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t IInputFlingerRust::readFromParcel(const AParcel* parcel, std::shared_ptr<IInputFlingerRust>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = IInputFlingerRust::fromBinder(binder);
  return STATUS_OK;
}
bool IInputFlingerRust::setDefaultImpl(const std::shared_ptr<IInputFlingerRust>& impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!IInputFlingerRust::default_impl);
  if (impl) {
    IInputFlingerRust::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<IInputFlingerRust>& IInputFlingerRust::getDefaultImpl() {
  return IInputFlingerRust::default_impl;
}
std::shared_ptr<IInputFlingerRust> IInputFlingerRust::default_impl = nullptr;
::ndk::ScopedAStatus IInputFlingerRustDefault::createInputFilter(const std::shared_ptr<::aidl::com::android::server::inputflinger::IInputFilter::IInputFilterCallbacks>& /*in_callbacks*/, std::shared_ptr<::aidl::com::android::server::inputflinger::IInputFilter>* /*_aidl_return*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder IInputFlingerRustDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool IInputFlingerRustDefault::isRemote() {
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
static binder_status_t _aidl_com_android_server_inputflinger_IInputFlingerRust_IInputFlingerRustBootstrapCallback_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<IInputFlingerRust::BnInputFlingerRustBootstrapCallback> _aidl_impl = std::static_pointer_cast<IInputFlingerRust::BnInputFlingerRustBootstrapCallback>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*onProvideInputFlingerRust*/): {
      std::shared_ptr<::aidl::com::android::server::inputflinger::IInputFlingerRust> in_inputFlingerRust;

      _aidl_ret_status = ::ndk::AParcel_readData(_aidl_in, &in_inputFlingerRust);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->onProvideInputFlingerRust(in_inputFlingerRust);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
  }
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_com_android_server_inputflinger_IInputFlingerRust_IInputFlingerRustBootstrapCallback_clazz = ::ndk::ICInterface::defineClass(IInputFlingerRust::IInputFlingerRustBootstrapCallback::descriptor, _aidl_com_android_server_inputflinger_IInputFlingerRust_IInputFlingerRustBootstrapCallback_onTransact);

IInputFlingerRust::BpInputFlingerRustBootstrapCallback::BpInputFlingerRustBootstrapCallback(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
IInputFlingerRust::BpInputFlingerRustBootstrapCallback::~BpInputFlingerRustBootstrapCallback() {}

::ndk::ScopedAStatus IInputFlingerRust::BpInputFlingerRustBootstrapCallback::onProvideInputFlingerRust(const std::shared_ptr<::aidl::com::android::server::inputflinger::IInputFlingerRust>& in_inputFlingerRust) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeData(_aidl_in.get(), in_inputFlingerRust);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*onProvideInputFlingerRust*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IInputFlingerRustBootstrapCallback::getDefaultImpl()) {
    _aidl_status = IInputFlingerRustBootstrapCallback::getDefaultImpl()->onProvideInputFlingerRust(in_inputFlingerRust);
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
// Source for BnInputFlingerRustBootstrapCallback
IInputFlingerRust::BnInputFlingerRustBootstrapCallback::BnInputFlingerRustBootstrapCallback() {}
IInputFlingerRust::BnInputFlingerRustBootstrapCallback::~BnInputFlingerRustBootstrapCallback() {}
::ndk::SpAIBinder IInputFlingerRust::BnInputFlingerRustBootstrapCallback::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_com_android_server_inputflinger_IInputFlingerRust_IInputFlingerRustBootstrapCallback_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for IInputFlingerRustBootstrapCallback
const char* IInputFlingerRust::IInputFlingerRustBootstrapCallback::descriptor = "com.android.server.inputflinger.IInputFlingerRust.IInputFlingerRustBootstrapCallback";
IInputFlingerRust::IInputFlingerRustBootstrapCallback::IInputFlingerRustBootstrapCallback() {}
IInputFlingerRust::IInputFlingerRustBootstrapCallback::~IInputFlingerRustBootstrapCallback() {}


std::shared_ptr<IInputFlingerRust::IInputFlingerRustBootstrapCallback> IInputFlingerRust::IInputFlingerRustBootstrapCallback::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_com_android_server_inputflinger_IInputFlingerRust_IInputFlingerRustBootstrapCallback_clazz)) {
    #if __ANDROID_API__ >= 31
    const AIBinder_Class* originalClass = AIBinder_getClass(binder.get());
    if (originalClass == nullptr) return nullptr;
    if (0 == strcmp(AIBinder_Class_getDescriptor(originalClass), descriptor)) {
      return ::ndk::SharedRefBase::make<IInputFlingerRust::BpInputFlingerRustBootstrapCallback>(binder);
    }
    #endif
    return nullptr;
  }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<IInputFlingerRustBootstrapCallback>(interface);
  }
  return ::ndk::SharedRefBase::make<IInputFlingerRust::BpInputFlingerRustBootstrapCallback>(binder);
}

binder_status_t IInputFlingerRust::IInputFlingerRustBootstrapCallback::writeToParcel(AParcel* parcel, const std::shared_ptr<IInputFlingerRustBootstrapCallback>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t IInputFlingerRust::IInputFlingerRustBootstrapCallback::readFromParcel(const AParcel* parcel, std::shared_ptr<IInputFlingerRustBootstrapCallback>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = IInputFlingerRustBootstrapCallback::fromBinder(binder);
  return STATUS_OK;
}
bool IInputFlingerRust::IInputFlingerRustBootstrapCallback::setDefaultImpl(const std::shared_ptr<IInputFlingerRustBootstrapCallback>& impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!IInputFlingerRustBootstrapCallback::default_impl);
  if (impl) {
    IInputFlingerRustBootstrapCallback::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<IInputFlingerRust::IInputFlingerRustBootstrapCallback>& IInputFlingerRust::IInputFlingerRustBootstrapCallback::getDefaultImpl() {
  return IInputFlingerRustBootstrapCallback::default_impl;
}
std::shared_ptr<IInputFlingerRust::IInputFlingerRustBootstrapCallback> IInputFlingerRust::IInputFlingerRustBootstrapCallback::default_impl = nullptr;
::ndk::ScopedAStatus IInputFlingerRust::IInputFlingerRustBootstrapCallbackDefault::onProvideInputFlingerRust(const std::shared_ptr<::aidl::com::android::server::inputflinger::IInputFlingerRust>& /*in_inputFlingerRust*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder IInputFlingerRust::IInputFlingerRustBootstrapCallbackDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool IInputFlingerRust::IInputFlingerRustBootstrapCallbackDefault::isRemote() {
  return false;
}
}  // namespace inputflinger
}  // namespace server
}  // namespace android
}  // namespace com
}  // namespace aidl
