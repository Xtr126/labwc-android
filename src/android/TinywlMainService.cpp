#include <aidl/com/xtr/tinywl/BnTinywlSurface.h>
#include <android/binder_ibinder_jni.h>
#include "TinywlInputService.hpp"
#include "aidl/com/xtr/tinywl/TinywlXdgTopLevelCallback.h"
#include "aidl/com/xtr/tinywl/WlrBox.h"
#include "aidl/com/xtr/tinywl/XdgTopLevel.h"
#include "android/binder_auto_utils.h"
#include "android/binder_interface_utils.h"
#include "android/native_window.h"
#include "buffer_presenter.h"
#include <android/looper.h>
#include <assert.h>
#include <cassert>
#include "ahb_wlr_allocator.h"

extern "C" {
  #include "labwc.h"
  #include "theme.h"
  #include "view.h"
  #include <wlr/util/log.h>
  #include <wlr/types/wlr_xdg_shell.h>
}

namespace tinywl {

  using namespace ::aidl::com::xtr::tinywl;

  static WlrBox WlrBox_from_wlr_box(struct wlr_box *wlr_box) {
    WlrBox wlrBox;
    wlrBox.x = wlr_box->x;
    wlrBox.y = wlr_box->y;
    wlrBox.width = wlr_box->width;
    wlrBox.height = wlr_box->height;
    return wlrBox;
  }

  class TinywlMainService : public BnTinywlSurface {
  public:
    ::ndk::ScopedAStatus onSurfaceChanged(const XdgTopLevel &in_xdgToplevel) override {
      struct view *view = reinterpret_cast<struct view *>(in_xdgToplevel.nativePtr);
      buffer_presenter_destroy(view->buffer_presenter);
      return onSurfaceCreated(in_xdgToplevel);
    }

    ::ndk::ScopedAStatus onSurfaceCreated(const XdgTopLevel &in_xdgToplevel) override {
      ANativeWindow *window = in_xdgToplevel.surface.get();
      struct view *view = reinterpret_cast<struct view *>(in_xdgToplevel.nativePtr);

      struct wlr_box* geo_box = &view->pending;

      wlr_log(WLR_DEBUG, "Setting buffers geometry for ANativeWindow to %dx%d", geo_box->width, geo_box->height);
      int ret = ANativeWindow_setBuffersGeometry(window, geo_box->width, geo_box->height ,AHB_FORMAT_PREFERRED);
      if (ret != 0) {
        wlr_log(WLR_ERROR, "Failed to set buffers geometry: %s (%d)", strerror(-ret), -ret);
      }
      
      view->buffer_presenter = buffer_presenter_create(window);

      mInputService->width = ANativeWindow_getWidth(window);
      mInputService->height = ANativeWindow_getWidth(window);

      return ::ndk::ScopedAStatus::ok();
    }

    ::ndk::ScopedAStatus onSurfaceDestroyed(const XdgTopLevel &in_xdgToplevel) override {
      struct view *view = reinterpret_cast<struct view *>(in_xdgToplevel.nativePtr);
      buffer_presenter_destroy(view->buffer_presenter);
      view->buffer_presenter = nullptr;
      return ::ndk::ScopedAStatus::ok();
    }

    void registerXdgTopLevelCallback() {
/*         server.callbacks.data = this;

        server.callbacks.xdg_toplevel_add = [](struct view *view, void* data) {
          auto thiz = reinterpret_cast<TinywlMainService *>(data);
          std::string appId;
          std::string title;
          if (view->type == LAB_XDG_SHELL_VIEW) {
            struct wlr_xdg_surface *xdg_surface = xdg_surface_from_view(view);
            if (xdg_surface->role == WLR_XDG_SURFACE_ROLE_TOPLEVEL) {
              if (xdg_surface->toplevel) {
                if (xdg_surface->toplevel->app_id) appId = xdg_surface->toplevel->app_id; 
                if (xdg_surface->toplevel->title) title = xdg_surface->toplevel->title; 
              }
            }
          }
          std::lock_guard<std::mutex> lock(thiz->mutex_);
          thiz->views.insert(view);
          thiz->mCallback->addXdgTopLevel(appId, title, (long)view, WlrBox_from_wlr_box(&view->pending));
        };

        server.callbacks.xdg_toplevel_remove = [](struct view *view, void* data) {
          auto thiz = reinterpret_cast<TinywlMainService *>(data);
          std::lock_guard<std::mutex> lock(thiz->mutex_);
          thiz->views.erase(view);

          std::string appId;
          std::string title;
          if (view->type == LAB_XDG_SHELL_VIEW) {
            struct wlr_xdg_surface *xdg_surface = xdg_surface_from_view(view);
            if (xdg_surface->role == WLR_XDG_SURFACE_ROLE_TOPLEVEL) {
              if (xdg_surface->toplevel) {
                if (xdg_surface->toplevel->app_id) appId = xdg_surface->toplevel->app_id; 
                if (xdg_surface->toplevel->title) title = xdg_surface->toplevel->title; 
              }
            }
          }

          thiz->mCallback->removeXdgTopLevel(
              appId,
              title,
              (long)view);          
        };
         */
    }

    const std::shared_ptr<TinywlInputService> mInputService = ndk::SharedRefBase::make<tinywl::TinywlInputService>();
    std::shared_ptr<ITinywlXdgTopLevelCallback> mCallback;

    struct server server;

  private:
      std::mutex &mutex_ = mInputService->mutex_;
      std::set<void *> &views = mInputService->views;
  };  // class TinywlMainService

}  // namespace tinywl

static auto gService = ndk::SharedRefBase::make<tinywl::TinywlMainService>();

extern "C"
JNIEXPORT void JNICALL
Java_com_xtr_tinywl_Tinywl_runTinywlLoop(JNIEnv *env, jclass clazz, jobjectArray args) {
  int argc = env->GetArrayLength(args);

  std::vector<char*> argStrings;
  argStrings.reserve(argc);

  for (int i = 0; i < argc; i++) {
      jstring jstr = (jstring)env->GetObjectArrayElement(args, i);
      const char* utf = env->GetStringUTFChars(jstr, nullptr);
      argStrings.emplace_back(const_cast<char*>(utf));
      env->ReleaseStringUTFChars(jstr, utf);
      env->DeleteLocalRef(jstr);
  }

  struct theme theme = { 0 };

  labwc_init(1280, 720, &gService->server, &theme, argc, argStrings.data());
  gService->mInputService->setTinywlServer(&gService->server);
  
  /* Handle event loop destroy */
  gService->mInputService->event_loop_destroy.notify = [](struct wl_listener *listener, void *data) {
    gService->mInputService->closeFdsAndRemoveEventSources();
  };
  
  struct wl_event_loop *loop = wl_display_get_event_loop(gService->server.wl_display);
  wl_event_loop_add_destroy_listener(loop, &gService->mInputService->event_loop_destroy);

  // Run loop
  labwc_run(&gService->server, &theme);
}

extern "C"
JNIEXPORT jobject JNICALL
Java_com_xtr_tinywl_Tinywl_nativeGetTinywlInputServiceBinder(JNIEnv *env, jclass clazz) {
    return AIBinder_toJavaBinder(env, gService->mInputService->asBinder().get());
}
extern "C"
JNIEXPORT jobject JNICALL
Java_com_xtr_tinywl_Tinywl_nativeGetTinywlSurfaceBinder(JNIEnv *env, jclass clazz) {
    return AIBinder_toJavaBinder(env, gService->asBinder().get());
}
extern "C"
JNIEXPORT void JNICALL
Java_com_xtr_tinywl_Tinywl_nativeRegisterXdgTopLevelCallback(JNIEnv *env, jclass clazz,
                                                             jobject binder) {
    AIBinder* pBinder = AIBinder_fromJavaBinder(env, binder);
    const ::ndk::SpAIBinder spBinder(pBinder);
    gService->mCallback = aidl::com::xtr::tinywl::ITinywlXdgTopLevelCallback::fromBinder(spBinder);
    gService->registerXdgTopLevelCallback();
    wlr_log(WLR_INFO, "Registered callback");
}