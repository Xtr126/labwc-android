/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl877169651209726230.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl/tinywl/ITinywlInput.aidl
 */
#include "aidl/tinywl/ITinywlInput.h"

#include <android/binder_parcel_utils.h>
#include <aidl/tinywl/BnTinywlInput.h>
#include <aidl/tinywl/BpTinywlInput.h>

namespace aidl {
namespace tinywl {
static binder_status_t _aidl_tinywl_ITinywlInput_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnTinywlInput> _aidl_impl = std::static_pointer_cast<BnTinywlInput>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*onKeyEvent*/): {
      ::aidl::com::android::server::inputflinger::KeyEvent in_event;
      int64_t in_nativePtr;
      bool _aidl_return;

      _aidl_ret_status = ::ndk::AParcel_readData(_aidl_in, &in_event);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readData(_aidl_in, &in_nativePtr);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->onKeyEvent(in_event, in_nativePtr, &_aidl_return);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = ::ndk::AParcel_writeData(_aidl_out, _aidl_return);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 1 /*onMotionEvent*/): {
      ::aidl::android::hardware::input::common::MotionEvent in_event;
      int64_t in_nativePtr;
      bool _aidl_return;

      _aidl_ret_status = ::ndk::AParcel_readData(_aidl_in, &in_event);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readData(_aidl_in, &in_nativePtr);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->onMotionEvent(in_event, in_nativePtr, &_aidl_return);
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

static AIBinder_Class* _g_aidl_tinywl_ITinywlInput_clazz = ::ndk::ICInterface::defineClass(ITinywlInput::descriptor, _aidl_tinywl_ITinywlInput_onTransact);

BpTinywlInput::BpTinywlInput(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpTinywlInput::~BpTinywlInput() {}

::ndk::ScopedAStatus BpTinywlInput::onKeyEvent(const ::aidl::com::android::server::inputflinger::KeyEvent& in_event, int64_t in_nativePtr, bool* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeData(_aidl_in.get(), in_event);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeData(_aidl_in.get(), in_nativePtr);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*onKeyEvent*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && ITinywlInput::getDefaultImpl()) {
    _aidl_status = ITinywlInput::getDefaultImpl()->onKeyEvent(in_event, in_nativePtr, _aidl_return);
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
::ndk::ScopedAStatus BpTinywlInput::onMotionEvent(const ::aidl::android::hardware::input::common::MotionEvent& in_event, int64_t in_nativePtr, bool* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeData(_aidl_in.get(), in_event);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeData(_aidl_in.get(), in_nativePtr);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 1 /*onMotionEvent*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && ITinywlInput::getDefaultImpl()) {
    _aidl_status = ITinywlInput::getDefaultImpl()->onMotionEvent(in_event, in_nativePtr, _aidl_return);
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
// Source for BnTinywlInput
BnTinywlInput::BnTinywlInput() {}
BnTinywlInput::~BnTinywlInput() {}
::ndk::SpAIBinder BnTinywlInput::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_tinywl_ITinywlInput_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for ITinywlInput
const char* ITinywlInput::descriptor = "tinywl.ITinywlInput";
ITinywlInput::ITinywlInput() {}
ITinywlInput::~ITinywlInput() {}


std::shared_ptr<ITinywlInput> ITinywlInput::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_tinywl_ITinywlInput_clazz)) {
    #if __ANDROID_API__ >= 31
    const AIBinder_Class* originalClass = AIBinder_getClass(binder.get());
    if (originalClass == nullptr) return nullptr;
    if (0 == strcmp(AIBinder_Class_getDescriptor(originalClass), descriptor)) {
      return ::ndk::SharedRefBase::make<BpTinywlInput>(binder);
    }
    #endif
    return nullptr;
  }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<ITinywlInput>(interface);
  }
  return ::ndk::SharedRefBase::make<BpTinywlInput>(binder);
}

binder_status_t ITinywlInput::writeToParcel(AParcel* parcel, const std::shared_ptr<ITinywlInput>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t ITinywlInput::readFromParcel(const AParcel* parcel, std::shared_ptr<ITinywlInput>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = ITinywlInput::fromBinder(binder);
  return STATUS_OK;
}
bool ITinywlInput::setDefaultImpl(const std::shared_ptr<ITinywlInput>& impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!ITinywlInput::default_impl);
  if (impl) {
    ITinywlInput::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<ITinywlInput>& ITinywlInput::getDefaultImpl() {
  return ITinywlInput::default_impl;
}
std::shared_ptr<ITinywlInput> ITinywlInput::default_impl = nullptr;
::ndk::ScopedAStatus ITinywlInputDefault::onKeyEvent(const ::aidl::com::android::server::inputflinger::KeyEvent& /*in_event*/, int64_t /*in_nativePtr*/, bool* /*_aidl_return*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus ITinywlInputDefault::onMotionEvent(const ::aidl::android::hardware::input::common::MotionEvent& /*in_event*/, int64_t /*in_nativePtr*/, bool* /*_aidl_return*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder ITinywlInputDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool ITinywlInputDefault::isRemote() {
  return false;
}
}  // namespace tinywl
}  // namespace aidl
