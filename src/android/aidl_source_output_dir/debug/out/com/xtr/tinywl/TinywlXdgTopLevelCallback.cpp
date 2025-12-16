/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl12317504132085319438.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl/com/xtr/tinywl/TinywlXdgTopLevelCallback.aidl
 */
#include "aidl/com/xtr/tinywl/TinywlXdgTopLevelCallback.h"

#include <android/binder_parcel_utils.h>
#include <aidl/com/xtr/tinywl/BnTinywlXdgTopLevelCallback.h>
#include <aidl/com/xtr/tinywl/BpTinywlXdgTopLevelCallback.h>

namespace aidl {
namespace com {
namespace xtr {
namespace tinywl {
static binder_status_t _aidl_com_xtr_tinywl_TinywlXdgTopLevelCallback_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnTinywlXdgTopLevelCallback> _aidl_impl = std::static_pointer_cast<BnTinywlXdgTopLevelCallback>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*addXdgTopLevel*/): {
      ::aidl::com::xtr::tinywl::XdgTopLevel in_xdgTopLevel;
      ::aidl::com::xtr::tinywl::WlrBox in_geoBox;

      _aidl_ret_status = ::ndk::AParcel_readData(_aidl_in, &in_xdgTopLevel);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readData(_aidl_in, &in_geoBox);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->addXdgTopLevel(in_xdgTopLevel, in_geoBox);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 1 /*removeXdgTopLevel*/): {
      ::aidl::com::xtr::tinywl::XdgTopLevel in_xdgTopLevel;

      _aidl_ret_status = ::ndk::AParcel_readData(_aidl_in, &in_xdgTopLevel);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->removeXdgTopLevel(in_xdgTopLevel);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
  }
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_com_xtr_tinywl_TinywlXdgTopLevelCallback_clazz = ::ndk::ICInterface::defineClass(ITinywlXdgTopLevelCallback::descriptor, _aidl_com_xtr_tinywl_TinywlXdgTopLevelCallback_onTransact);

BpTinywlXdgTopLevelCallback::BpTinywlXdgTopLevelCallback(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpTinywlXdgTopLevelCallback::~BpTinywlXdgTopLevelCallback() {}

::ndk::ScopedAStatus BpTinywlXdgTopLevelCallback::addXdgTopLevel(const ::aidl::com::xtr::tinywl::XdgTopLevel& in_xdgTopLevel, const ::aidl::com::xtr::tinywl::WlrBox& in_geoBox) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeData(_aidl_in.get(), in_xdgTopLevel);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeData(_aidl_in.get(), in_geoBox);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*addXdgTopLevel*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && ITinywlXdgTopLevelCallback::getDefaultImpl()) {
    _aidl_status = ITinywlXdgTopLevelCallback::getDefaultImpl()->addXdgTopLevel(in_xdgTopLevel, in_geoBox);
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
::ndk::ScopedAStatus BpTinywlXdgTopLevelCallback::removeXdgTopLevel(const ::aidl::com::xtr::tinywl::XdgTopLevel& in_xdgTopLevel) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeData(_aidl_in.get(), in_xdgTopLevel);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 1 /*removeXdgTopLevel*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && ITinywlXdgTopLevelCallback::getDefaultImpl()) {
    _aidl_status = ITinywlXdgTopLevelCallback::getDefaultImpl()->removeXdgTopLevel(in_xdgTopLevel);
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
// Source for BnTinywlXdgTopLevelCallback
BnTinywlXdgTopLevelCallback::BnTinywlXdgTopLevelCallback() {}
BnTinywlXdgTopLevelCallback::~BnTinywlXdgTopLevelCallback() {}
::ndk::SpAIBinder BnTinywlXdgTopLevelCallback::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_com_xtr_tinywl_TinywlXdgTopLevelCallback_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for ITinywlXdgTopLevelCallback
const char* ITinywlXdgTopLevelCallback::descriptor = "com.xtr.tinywl.TinywlXdgTopLevelCallback";
ITinywlXdgTopLevelCallback::ITinywlXdgTopLevelCallback() {}
ITinywlXdgTopLevelCallback::~ITinywlXdgTopLevelCallback() {}


std::shared_ptr<ITinywlXdgTopLevelCallback> ITinywlXdgTopLevelCallback::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_com_xtr_tinywl_TinywlXdgTopLevelCallback_clazz)) {
    #if __ANDROID_API__ >= 31
    const AIBinder_Class* originalClass = AIBinder_getClass(binder.get());
    if (originalClass == nullptr) return nullptr;
    if (0 == strcmp(AIBinder_Class_getDescriptor(originalClass), descriptor)) {
      return ::ndk::SharedRefBase::make<BpTinywlXdgTopLevelCallback>(binder);
    }
    #endif
    return nullptr;
  }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<ITinywlXdgTopLevelCallback>(interface);
  }
  return ::ndk::SharedRefBase::make<BpTinywlXdgTopLevelCallback>(binder);
}

binder_status_t ITinywlXdgTopLevelCallback::writeToParcel(AParcel* parcel, const std::shared_ptr<ITinywlXdgTopLevelCallback>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t ITinywlXdgTopLevelCallback::readFromParcel(const AParcel* parcel, std::shared_ptr<ITinywlXdgTopLevelCallback>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = ITinywlXdgTopLevelCallback::fromBinder(binder);
  return STATUS_OK;
}
bool ITinywlXdgTopLevelCallback::setDefaultImpl(const std::shared_ptr<ITinywlXdgTopLevelCallback>& impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!ITinywlXdgTopLevelCallback::default_impl);
  if (impl) {
    ITinywlXdgTopLevelCallback::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<ITinywlXdgTopLevelCallback>& ITinywlXdgTopLevelCallback::getDefaultImpl() {
  return ITinywlXdgTopLevelCallback::default_impl;
}
std::shared_ptr<ITinywlXdgTopLevelCallback> ITinywlXdgTopLevelCallback::default_impl = nullptr;
::ndk::ScopedAStatus ITinywlXdgTopLevelCallbackDefault::addXdgTopLevel(const ::aidl::com::xtr::tinywl::XdgTopLevel& /*in_xdgTopLevel*/, const ::aidl::com::xtr::tinywl::WlrBox& /*in_geoBox*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus ITinywlXdgTopLevelCallbackDefault::removeXdgTopLevel(const ::aidl::com::xtr::tinywl::XdgTopLevel& /*in_xdgTopLevel*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder ITinywlXdgTopLevelCallbackDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool ITinywlXdgTopLevelCallbackDefault::isRemote() {
  return false;
}
}  // namespace tinywl
}  // namespace xtr
}  // namespace com
}  // namespace aidl
