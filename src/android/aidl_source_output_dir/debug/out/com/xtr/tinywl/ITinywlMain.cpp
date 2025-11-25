/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl2453284031907475535.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl/com/xtr/tinywl/ITinywlMain.aidl
 */
#include "aidl/com/xtr/tinywl/ITinywlMain.h"

#include <android/binder_parcel_utils.h>
#include <aidl/com/xtr/tinywl/BnTinywlMain.h>
#include <aidl/com/xtr/tinywl/BnTinywlXdgTopLevelCallback.h>
#include <aidl/com/xtr/tinywl/BpTinywlMain.h>
#include <aidl/com/xtr/tinywl/BpTinywlXdgTopLevelCallback.h>
#include <aidl/com/xtr/tinywl/TinywlXdgTopLevelCallback.h>

namespace aidl {
namespace com {
namespace xtr {
namespace tinywl {
static binder_status_t _aidl_com_xtr_tinywl_ITinywlMain_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnTinywlMain> _aidl_impl = std::static_pointer_cast<BnTinywlMain>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*registerXdgTopLevelCallback*/): {
      std::shared_ptr<::aidl::com::xtr::tinywl::ITinywlXdgTopLevelCallback> in_xdgTopLevelCallback;

      _aidl_ret_status = ::ndk::AParcel_readData(_aidl_in, &in_xdgTopLevelCallback);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->registerXdgTopLevelCallback(in_xdgTopLevelCallback);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
  }
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_com_xtr_tinywl_ITinywlMain_clazz = ::ndk::ICInterface::defineClass(ITinywlMain::descriptor, _aidl_com_xtr_tinywl_ITinywlMain_onTransact);

BpTinywlMain::BpTinywlMain(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpTinywlMain::~BpTinywlMain() {}

::ndk::ScopedAStatus BpTinywlMain::registerXdgTopLevelCallback(const std::shared_ptr<::aidl::com::xtr::tinywl::ITinywlXdgTopLevelCallback>& in_xdgTopLevelCallback) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeData(_aidl_in.get(), in_xdgTopLevelCallback);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*registerXdgTopLevelCallback*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && ITinywlMain::getDefaultImpl()) {
    _aidl_status = ITinywlMain::getDefaultImpl()->registerXdgTopLevelCallback(in_xdgTopLevelCallback);
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
// Source for BnTinywlMain
BnTinywlMain::BnTinywlMain() {}
BnTinywlMain::~BnTinywlMain() {}
::ndk::SpAIBinder BnTinywlMain::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_com_xtr_tinywl_ITinywlMain_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for ITinywlMain
const char* ITinywlMain::descriptor = "com.xtr.tinywl.ITinywlMain";
ITinywlMain::ITinywlMain() {}
ITinywlMain::~ITinywlMain() {}


std::shared_ptr<ITinywlMain> ITinywlMain::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_com_xtr_tinywl_ITinywlMain_clazz)) {
    #if __ANDROID_API__ >= 31
    const AIBinder_Class* originalClass = AIBinder_getClass(binder.get());
    if (originalClass == nullptr) return nullptr;
    if (0 == strcmp(AIBinder_Class_getDescriptor(originalClass), descriptor)) {
      return ::ndk::SharedRefBase::make<BpTinywlMain>(binder);
    }
    #endif
    return nullptr;
  }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<ITinywlMain>(interface);
  }
  return ::ndk::SharedRefBase::make<BpTinywlMain>(binder);
}

binder_status_t ITinywlMain::writeToParcel(AParcel* parcel, const std::shared_ptr<ITinywlMain>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t ITinywlMain::readFromParcel(const AParcel* parcel, std::shared_ptr<ITinywlMain>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = ITinywlMain::fromBinder(binder);
  return STATUS_OK;
}
bool ITinywlMain::setDefaultImpl(const std::shared_ptr<ITinywlMain>& impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!ITinywlMain::default_impl);
  if (impl) {
    ITinywlMain::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<ITinywlMain>& ITinywlMain::getDefaultImpl() {
  return ITinywlMain::default_impl;
}
std::shared_ptr<ITinywlMain> ITinywlMain::default_impl = nullptr;
::ndk::ScopedAStatus ITinywlMainDefault::registerXdgTopLevelCallback(const std::shared_ptr<::aidl::com::xtr::tinywl::ITinywlXdgTopLevelCallback>& /*in_xdgTopLevelCallback*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder ITinywlMainDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool ITinywlMainDefault::isRemote() {
  return false;
}
}  // namespace tinywl
}  // namespace xtr
}  // namespace com
}  // namespace aidl
