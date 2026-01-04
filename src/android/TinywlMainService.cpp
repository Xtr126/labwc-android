#include <aidl/com/xtr/tinywl/BnTinywlSurface.h>
#include <android/binder_ibinder_jni.h>
#include "TinywlInputService.hpp"
#include "aidl/com/xtr/tinywl/TinywlXdgTopLevelCallback.h"
#include <assert.h>
#include <queue>

extern "C" {
  #include "ahb_wlr_allocator.h"
  #include "theme.h"
  #include <wlr/types/wlr_xdg_shell.h>
  #include <wlr/render/drm_format_set.h>
}

namespace tinywl {

  using namespace ::aidl::com::xtr::tinywl;

  static WlrBox WlrBox_from_wlr_box(struct wlr_box *wlr_box) {
    WlrBox wlrBox;
    if (wlr_box) {
    	wlrBox.x = wlr_box->x;
    	wlrBox.y = wlr_box->y;
    	wlrBox.width = wlr_box->width;
    	wlrBox.height = wlr_box->height;
    }
    return wlrBox;
  }

  static XdgTopLevel newXdgTopLevelWithType(const std::string& in_appId, const std::string& in_title, int64_t in_nativePtr, const NativePtrType nativePtrType) {
    XdgTopLevel toplevel;
    toplevel.appId = in_appId;
    toplevel.title = in_title;
    toplevel.nativePtr = in_nativePtr;
    toplevel.nativePtrType = nativePtrType;
    return toplevel;
  }

  static XdgTopLevel newXdgTopLevel(const std::string& in_appId, const std::string& in_title, const int64_t in_nativePtr) {
    return newXdgTopLevelWithType(in_appId, in_title, in_nativePtr, NativePtrType::VIEW);
  }

  class TinywlMainService : public BnTinywlSurface {
  public:
    ::ndk::ScopedAStatus onSurfaceChanged(int64_t in_nativePtr, ::aidl::com::xtr::tinywl::NativePtrType in_nativePtrType, const ::aidl::android::view::Surface& in_surface) override {
      if (in_nativePtrType == NativePtrType::VIEW) {
        struct view *view = reinterpret_cast<struct view *>(in_nativePtr);
        buffer_presenter_destroy(view->buffer_presenter);
      } else {
        struct output *output = reinterpret_cast<struct output *>(in_nativePtr);
        buffer_presenter_destroy(output->buffer_presenter);
      }
      return onSurfaceCreated(in_nativePtr, in_nativePtrType, in_surface);
    }

    ::ndk::ScopedAStatus onSurfaceCreated(int64_t in_nativePtr, ::aidl::com::xtr::tinywl::NativePtrType in_nativePtrType, const ::aidl::android::view::Surface& in_surface) override {
      ANativeWindow *window = in_surface.get();
      if (in_nativePtrType == NativePtrType::VIEW) {
        struct view *view = reinterpret_cast<struct view *>(in_nativePtr);

        struct wlr_box* geo_box = &view->pending;

        wlr_log(WLR_DEBUG, "Setting buffers geometry for ANativeWindow to %dx%d", geo_box->width, geo_box->height);
        int ret = ANativeWindow_setBuffersGeometry(window, geo_box->width, geo_box->height ,AHB_FORMAT_PREFERRED);
        if (ret != 0) {
          wlr_log(WLR_ERROR, "Failed to set buffers geometry: %s (%d)", strerror(-ret), -ret);
        }
        
        view->buffer_presenter = buffer_presenter_create(window);
      } else {
        struct output *output = reinterpret_cast<struct output *>(in_nativePtr);
                wlr_log(WLR_DEBUG, "Setting buffers geometry for ANativeWindow to %dx%d", output->wlr_output->height, output->wlr_output->height);
        int ret = ANativeWindow_setBuffersGeometry(window, output->wlr_output->width, output->wlr_output->height ,AHB_FORMAT_PREFERRED);
        if (ret != 0) {
          wlr_log(WLR_ERROR, "Failed to set buffers geometry: %s (%d)", strerror(-ret), -ret);
        }
        
        output->buffer_presenter = buffer_presenter_create(window);
      }
      return ::ndk::ScopedAStatus::ok();
    }

    ::ndk::ScopedAStatus onSurfaceDestroyed(int64_t in_nativePtr, ::aidl::com::xtr::tinywl::NativePtrType in_nativePtrType) override {
      if (in_nativePtrType == NativePtrType::VIEW) {
        struct view *view = reinterpret_cast<struct view *>(in_nativePtr);
        buffer_presenter_destroy(view->buffer_presenter);
        view->buffer_presenter = nullptr;
        wlr_buffer_drop(&view->android_buffer->base);
        view->android_buffer = nullptr;
      } else {
        struct output *output = reinterpret_cast<struct output *>(in_nativePtr);
        buffer_presenter_destroy(output->buffer_presenter);
        output->buffer_presenter = nullptr;
      }
      return ::ndk::ScopedAStatus::ok();
    }

    void registerCallbacks() {
        server.callbacks.data = this;

        server.callbacks.view_add = [](struct view *view) {

          if (view->android_buffer == NULL) {
            assert(view->surface->buffer != NULL);

            /* Get the format from the client buffer
            struct wlr_buffer *client_buffer = &toplevel->xdg_toplevel->base->surface->buffer->base;
            struct wlr_dmabuf_attributes attribs;
            wlr_buffer_get_dmabuf(client_buffer, &attribs);
            const struct wlr_drm_format format = {attribs.format};*/

            const struct wlr_drm_format format = {AHB_FORMAT_PREFERRED_DRM};
            
            // Create an AHardwareBuffer backed wlr_buffer for presenting
            struct wlr_box* geo_box = &view->pending;
            struct wlr_buffer* buffer = wlr_allocator_create_buffer(view->server->allocator, geo_box->width, geo_box->height, &format);
            view->android_buffer = get_ahb_buffer_from_buffer(buffer);
          }

          auto thiz = reinterpret_cast<TinywlMainService *>(view->server->callbacks.data);
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
          thiz->views.emplace(view, NativePtrType::VIEW);
          auto xdgToplevel = newXdgTopLevel(appId, title, (long)view);

          thiz->runWhenCallbackAvailable([=] {
            thiz->mCallback->addXdgTopLevel(xdgToplevel, WlrBox_from_wlr_box(&view->pending));
          });
        };

        server.callbacks.view_remove = [](struct view *view) {
          auto thiz = reinterpret_cast<TinywlMainService *>(view->server->callbacks.data);
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
          thiz->runWhenCallbackAvailable([=] {
            thiz->mCallback->removeXdgTopLevel(
                newXdgTopLevel(appId,
                title,
                (long)view));     
          });
        };
        
        server.callbacks.view_commit = android_view_present_buffer;
        
        server.callbacks.output_commit = android_output_present_buffer;
        server.callbacks.output_init = [](struct output *output) {
          auto thiz = reinterpret_cast<TinywlMainService *>(output->server->callbacks.data);
          thiz->views.emplace(output, NativePtrType::OUTPUT);
          // To be run when mCallback is available
          thiz->runWhenCallbackAvailable([thiz, output] {
            thiz->mCallback->addXdgTopLevel(newXdgTopLevelWithType("output-" + std::to_string(output->id_bit), "Output", (long)output, NativePtrType::OUTPUT), WlrBox_from_wlr_box(nullptr));           
          });
        };  

        server.callbacks.output_destroy = [](struct output *output) {
          auto thiz = reinterpret_cast<TinywlMainService *>(output->server->callbacks.data);
          thiz->views.erase(output);
          // To be run when mCallback is available
          thiz->runWhenCallbackAvailable([thiz, output] {
            thiz->mCallback->removeXdgTopLevel(newXdgTopLevelWithType(
              "output-" + std::to_string(output->id_bit), "Output",
              (long)output, NativePtrType::OUTPUT));
          });
        };
    }
    
    const std::shared_ptr<TinywlInputService> mInputService = ndk::SharedRefBase::make<tinywl::TinywlInputService>();
    std::shared_ptr<ITinywlXdgTopLevelCallback> mCallback;
    
    struct server server;
    std::queue<std::function<void()>> mTaskQueue;
    
    private:
      void runWhenCallbackAvailable(std::function<void()> task) {
        if (!mCallback)
          // Push to queue to be run later when mCallback is available
          mTaskQueue.push(std::move(task));
        else 
          // Execute task now
          task();
      }
      
      std::mutex &mutex_ = mInputService->mutex_;
      std::map<void *, NativePtrType> &views = mInputService->views;
  };  // class TinywlMainService

}  // namespace tinywl

static auto gService = ndk::SharedRefBase::make<tinywl::TinywlMainService>();

extern "C"
JNIEXPORT void JNICALL
Java_com_xtr_tinywl_Tinywl_runTinywlLoop(JNIEnv *env, jclass clazz, jobjectArray args) {
  int argc = env->GetArrayLength(args);

  std::vector<char*> argStrings;
  argStrings.reserve(argc + 1);  // +1 for the required NULL terminator for getopt

  for (int i = 0; i < argc; i++) {
      jstring jstr = (jstring)env->GetObjectArrayElement(args, i);
      const char* utf = env->GetStringUTFChars(jstr, nullptr);

      char* copy = strdup(utf);  
      argStrings.emplace_back(copy);

      env->ReleaseStringUTFChars(jstr, utf);
      env->DeleteLocalRef(jstr);
  }

  // getopt requires argv[argc] == NULL
  argStrings.push_back(nullptr);

  struct theme theme = { 0 };
  
  gService->registerCallbacks();
  // init labwc
  auto idle_ctx = labwc_init(1280, 720, &gService->server, &theme, argc, argStrings.data());
  gService->mInputService->setTinywlServer(&gService->server);
  
  /* Handle event loop destroy */
  gService->mInputService->event_loop_destroy.notify = [](struct wl_listener *listener, void *data) {
    gService->mInputService->closeFdsAndRemoveEventSources();
  };
  
  struct wl_event_loop *loop = wl_display_get_event_loop(gService->server.wl_display);
  wl_event_loop_add_destroy_listener(loop, &gService->mInputService->event_loop_destroy);

  // Run loop
  labwc_run(&gService->server, &theme, &idle_ctx);
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
    wlr_log(WLR_INFO, "Registered callback");
                                                            
    // Tasks queued to run when mCallback is available
    while (!gService->mTaskQueue.empty()) {
      /* Execute task and remove it from the queue */
      auto task = gService->mTaskQueue.front(); 
    	task(); 
    	gService->mTaskQueue.pop();
    }
}
