/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: /home/hp/Android/Sdk/build-tools/35.0.0/aidl --lang=ndk -o/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -h/home/hp/Desktop/wlroots-android-bridge/tinywl/build/generated/aidl_source_output_dir/debug/out/ndk -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/debug/aidl -I/home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/cpp/aidl -d/tmp/aidl4154290964388247707.d /home/hp/Desktop/wlroots-android-bridge/tinywl/src/main/aidl/com/xtr/tinywl/ITinywlSurface.aidl
 */
#include "aidl/com/xtr/tinywl/ITinywlSurface.h"

#include <android/binder_parcel_utils.h>
#include <aidl/com/xtr/tinywl/BnTinywlSurface.h>
#include <aidl/com/xtr/tinywl/BpTinywlSurface.h>

namespace aidl {
namespace com {
namespace xtr {
namespace tinywl {
static binder_status_t _aidl_com_xtr_tinywl_ITinywlSurface_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnTinywlSurface> _aidl_impl = std::static_pointer_cast<BnTinywlSurface>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*onSurfaceCreated*/): {
      ::aidl::com::xtr::tinywl::XdgTopLevel in_xdgToplevel;

      _aidl_ret_status = ::ndk::AParcel_readData(_aidl_in, &in_xdgToplevel);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->onSurfaceCreated(in_xdgToplevel);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 1 /*onSurfaceChanged*/): {
      ::aidl::com::xtr::tinywl::XdgTopLevel in_xdgToplevel;

      _aidl_ret_status = ::ndk::AParcel_readData(_aidl_in, &in_xdgToplevel);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->onSurfaceChanged(in_xdgToplevel);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 2 /*onSurfaceDestroyed*/): {
      ::aidl::com::xtr::tinywl::XdgTopLevel in_xdgToplevel;

      _aidl_ret_status = ::ndk::AParcel_readData(_aidl_in, &in_xdgToplevel);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->onSurfaceDestroyed(in_xdgToplevel);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
  }
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_com_xtr_tinywl_ITinywlSurface_clazz = ::ndk::ICInterface::defineClass(ITinywlSurface::descriptor, _aidl_com_xtr_tinywl_ITinywlSurface_onTransact);

BpTinywlSurface::BpTinywlSurface(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpTinywlSurface::~BpTinywlSurface() {}

::ndk::ScopedAStatus BpTinywlSurface::onSurfaceCreated(const ::aidl::com::xtr::tinywl::XdgTopLevel& in_xdgToplevel) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeData(_aidl_in.get(), in_xdgToplevel);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*onSurfaceCreated*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && ITinywlSurface::getDefaultImpl()) {
    _aidl_status = ITinywlSurface::getDefaultImpl()->onSurfaceCreated(in_xdgToplevel);
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
::ndk::ScopedAStatus BpTinywlSurface::onSurfaceChanged(const ::aidl::com::xtr::tinywl::XdgTopLevel& in_xdgToplevel) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeData(_aidl_in.get(), in_xdgToplevel);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 1 /*onSurfaceChanged*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && ITinywlSurface::getDefaultImpl()) {
    _aidl_status = ITinywlSurface::getDefaultImpl()->onSurfaceChanged(in_xdgToplevel);
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
::ndk::ScopedAStatus BpTinywlSurface::onSurfaceDestroyed(const ::aidl::com::xtr::tinywl::XdgTopLevel& in_xdgToplevel) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeData(_aidl_in.get(), in_xdgToplevel);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 2 /*onSurfaceDestroyed*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && ITinywlSurface::getDefaultImpl()) {
    _aidl_status = ITinywlSurface::getDefaultImpl()->onSurfaceDestroyed(in_xdgToplevel);
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
// Source for BnTinywlSurface
BnTinywlSurface::BnTinywlSurface() {}
BnTinywlSurface::~BnTinywlSurface() {}
::ndk::SpAIBinder BnTinywlSurface::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_com_xtr_tinywl_ITinywlSurface_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for ITinywlSurface
const char* ITinywlSurface::descriptor = "com.xtr.tinywl.ITinywlSurface";
ITinywlSurface::ITinywlSurface() {}
ITinywlSurface::~ITinywlSurface() {}


std::shared_ptr<ITinywlSurface> ITinywlSurface::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_com_xtr_tinywl_ITinywlSurface_clazz)) {
    #if __ANDROID_API__ >= 31
    const AIBinder_Class* originalClass = AIBinder_getClass(binder.get());
    if (originalClass == nullptr) return nullptr;
    if (0 == strcmp(AIBinder_Class_getDescriptor(originalClass), descriptor)) {
      return ::ndk::SharedRefBase::make<BpTinywlSurface>(binder);
    }
    #endif
    return nullptr;
  }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<ITinywlSurface>(interface);
  }
  return ::ndk::SharedRefBase::make<BpTinywlSurface>(binder);
}

binder_status_t ITinywlSurface::writeToParcel(AParcel* parcel, const std::shared_ptr<ITinywlSurface>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t ITinywlSurface::readFromParcel(const AParcel* parcel, std::shared_ptr<ITinywlSurface>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = ITinywlSurface::fromBinder(binder);
  return STATUS_OK;
}
bool ITinywlSurface::setDefaultImpl(const std::shared_ptr<ITinywlSurface>& impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!ITinywlSurface::default_impl);
  if (impl) {
    ITinywlSurface::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<ITinywlSurface>& ITinywlSurface::getDefaultImpl() {
  return ITinywlSurface::default_impl;
}
std::shared_ptr<ITinywlSurface> ITinywlSurface::default_impl = nullptr;
::ndk::ScopedAStatus ITinywlSurfaceDefault::onSurfaceCreated(const ::aidl::com::xtr::tinywl::XdgTopLevel& /*in_xdgToplevel*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus ITinywlSurfaceDefault::onSurfaceChanged(const ::aidl::com::xtr::tinywl::XdgTopLevel& /*in_xdgToplevel*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus ITinywlSurfaceDefault::onSurfaceDestroyed(const ::aidl::com::xtr::tinywl::XdgTopLevel& /*in_xdgToplevel*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder ITinywlSurfaceDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool ITinywlSurfaceDefault::isRemote() {
  return false;
}
}  // namespace tinywl
}  // namespace xtr
}  // namespace com
}  // namespace aidl
