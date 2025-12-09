/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl10612235381581850503.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl/com/android/server/inputflinger/IInputThread.aidl
 */
#include "aidl/com/android/server/inputflinger/IInputThread.h"

#include <android/binder_parcel_utils.h>
#include <aidl/com/android/server/inputflinger/BnInputThread.h>
#include <aidl/com/android/server/inputflinger/BpInputThread.h>

namespace aidl {
namespace com {
namespace android {
namespace server {
namespace inputflinger {
static binder_status_t _aidl_com_android_server_inputflinger_IInputThread_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnInputThread> _aidl_impl = std::static_pointer_cast<BnInputThread>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*finish*/): {

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->finish();
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 1 /*wake*/): {

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->wake();
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 2 /*sleepUntil*/): {
      int64_t in_whenNanos;

      _aidl_ret_status = ::ndk::AParcel_readData(_aidl_in, &in_whenNanos);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->sleepUntil(in_whenNanos);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
  }
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_com_android_server_inputflinger_IInputThread_clazz = ::ndk::ICInterface::defineClass(IInputThread::descriptor, _aidl_com_android_server_inputflinger_IInputThread_onTransact);

BpInputThread::BpInputThread(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpInputThread::~BpInputThread() {}

::ndk::ScopedAStatus BpInputThread::finish() {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*finish*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IInputThread::getDefaultImpl()) {
    _aidl_status = IInputThread::getDefaultImpl()->finish();
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
::ndk::ScopedAStatus BpInputThread::wake() {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 1 /*wake*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IInputThread::getDefaultImpl()) {
    _aidl_status = IInputThread::getDefaultImpl()->wake();
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
::ndk::ScopedAStatus BpInputThread::sleepUntil(int64_t in_whenNanos) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeData(_aidl_in.get(), in_whenNanos);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 2 /*sleepUntil*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IInputThread::getDefaultImpl()) {
    _aidl_status = IInputThread::getDefaultImpl()->sleepUntil(in_whenNanos);
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
// Source for BnInputThread
BnInputThread::BnInputThread() {}
BnInputThread::~BnInputThread() {}
::ndk::SpAIBinder BnInputThread::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_com_android_server_inputflinger_IInputThread_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for IInputThread
const char* IInputThread::descriptor = "com.android.server.inputflinger.IInputThread";
IInputThread::IInputThread() {}
IInputThread::~IInputThread() {}


std::shared_ptr<IInputThread> IInputThread::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_com_android_server_inputflinger_IInputThread_clazz)) {
    #if __ANDROID_API__ >= 31
    const AIBinder_Class* originalClass = AIBinder_getClass(binder.get());
    if (originalClass == nullptr) return nullptr;
    if (0 == strcmp(AIBinder_Class_getDescriptor(originalClass), descriptor)) {
      return ::ndk::SharedRefBase::make<BpInputThread>(binder);
    }
    #endif
    return nullptr;
  }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<IInputThread>(interface);
  }
  return ::ndk::SharedRefBase::make<BpInputThread>(binder);
}

binder_status_t IInputThread::writeToParcel(AParcel* parcel, const std::shared_ptr<IInputThread>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t IInputThread::readFromParcel(const AParcel* parcel, std::shared_ptr<IInputThread>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = IInputThread::fromBinder(binder);
  return STATUS_OK;
}
bool IInputThread::setDefaultImpl(const std::shared_ptr<IInputThread>& impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!IInputThread::default_impl);
  if (impl) {
    IInputThread::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<IInputThread>& IInputThread::getDefaultImpl() {
  return IInputThread::default_impl;
}
std::shared_ptr<IInputThread> IInputThread::default_impl = nullptr;
::ndk::ScopedAStatus IInputThreadDefault::finish() {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IInputThreadDefault::wake() {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IInputThreadDefault::sleepUntil(int64_t /*in_whenNanos*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder IInputThreadDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool IInputThreadDefault::isRemote() {
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
static binder_status_t _aidl_com_android_server_inputflinger_IInputThread_IInputThreadCallback_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<IInputThread::BnInputThreadCallback> _aidl_impl = std::static_pointer_cast<IInputThread::BnInputThreadCallback>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*loopOnce*/): {

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->loopOnce();
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
  }
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_com_android_server_inputflinger_IInputThread_IInputThreadCallback_clazz = ::ndk::ICInterface::defineClass(IInputThread::IInputThreadCallback::descriptor, _aidl_com_android_server_inputflinger_IInputThread_IInputThreadCallback_onTransact);

IInputThread::BpInputThreadCallback::BpInputThreadCallback(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
IInputThread::BpInputThreadCallback::~BpInputThreadCallback() {}

::ndk::ScopedAStatus IInputThread::BpInputThreadCallback::loopOnce() {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*loopOnce*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IInputThreadCallback::getDefaultImpl()) {
    _aidl_status = IInputThreadCallback::getDefaultImpl()->loopOnce();
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
// Source for BnInputThreadCallback
IInputThread::BnInputThreadCallback::BnInputThreadCallback() {}
IInputThread::BnInputThreadCallback::~BnInputThreadCallback() {}
::ndk::SpAIBinder IInputThread::BnInputThreadCallback::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_com_android_server_inputflinger_IInputThread_IInputThreadCallback_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for IInputThreadCallback
const char* IInputThread::IInputThreadCallback::descriptor = "com.android.server.inputflinger.IInputThread.IInputThreadCallback";
IInputThread::IInputThreadCallback::IInputThreadCallback() {}
IInputThread::IInputThreadCallback::~IInputThreadCallback() {}


std::shared_ptr<IInputThread::IInputThreadCallback> IInputThread::IInputThreadCallback::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_com_android_server_inputflinger_IInputThread_IInputThreadCallback_clazz)) {
    #if __ANDROID_API__ >= 31
    const AIBinder_Class* originalClass = AIBinder_getClass(binder.get());
    if (originalClass == nullptr) return nullptr;
    if (0 == strcmp(AIBinder_Class_getDescriptor(originalClass), descriptor)) {
      return ::ndk::SharedRefBase::make<IInputThread::BpInputThreadCallback>(binder);
    }
    #endif
    return nullptr;
  }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<IInputThreadCallback>(interface);
  }
  return ::ndk::SharedRefBase::make<IInputThread::BpInputThreadCallback>(binder);
}

binder_status_t IInputThread::IInputThreadCallback::writeToParcel(AParcel* parcel, const std::shared_ptr<IInputThreadCallback>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t IInputThread::IInputThreadCallback::readFromParcel(const AParcel* parcel, std::shared_ptr<IInputThreadCallback>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = IInputThreadCallback::fromBinder(binder);
  return STATUS_OK;
}
bool IInputThread::IInputThreadCallback::setDefaultImpl(const std::shared_ptr<IInputThreadCallback>& impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!IInputThreadCallback::default_impl);
  if (impl) {
    IInputThreadCallback::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<IInputThread::IInputThreadCallback>& IInputThread::IInputThreadCallback::getDefaultImpl() {
  return IInputThreadCallback::default_impl;
}
std::shared_ptr<IInputThread::IInputThreadCallback> IInputThread::IInputThreadCallback::default_impl = nullptr;
::ndk::ScopedAStatus IInputThread::IInputThreadCallbackDefault::loopOnce() {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder IInputThread::IInputThreadCallbackDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool IInputThread::IInputThreadCallbackDefault::isRemote() {
  return false;
}
}  // namespace inputflinger
}  // namespace server
}  // namespace android
}  // namespace com
}  // namespace aidl
