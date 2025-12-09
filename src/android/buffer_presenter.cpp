#include "buffer_presenter.h"

#include <android/api-level.h>
#include <android/surface_control.h>
#include <android/log.h>
#include <new>
#include <unistd.h> // For close()
#include <android/api-level.h> // For close()

extern "C" {
    #include <wlr/util/log.h>
} 
#define ALOGE(...) wlr_log(WLR_ERROR, __VA_ARGS__)
#define ALOGI(...) wlr_log(WLR_DEBUG, __VA_ARGS__)

/**
 * @brief The internal state of the BufferManager.
 */
struct BufferManager {
    ASurfaceControl* surface_control;
};


/** 
* This struct is used on older APIs to pass the user's callback
* and context through the ASurfaceTransaction_setOnComplete mechanism
* to our adapter
*/
struct OnCompleteContext {
    BufferManager_OnReleaseCallback user_callback;
    void* user_context;
};

/**
 * @brief OnComplete callback for APIs < 36.
 *
 * This function is registered with ASurfaceTransaction_setOnComplete.
 */
static void on_complete_pre_api36(void* context, ASurfaceTransactionStats* stats) {
    if (!context || !stats) {
        if (context) delete static_cast<OnCompleteContext*>(context);
        ALOGE("Pre API 36 adapter callback received null context or stats.");
        return;
    }

    OnCompleteContext* wrapped_context = static_cast<OnCompleteContext*>(context);


    if (wrapped_context->user_callback) {
        wrapped_context->user_callback(wrapped_context->user_context, -1 /* Already released */);
    } 

    // Clean up the context wrapper we allocated.
    delete wrapped_context;
}

// --- End of API-specific implementation details ---


BufferManager* buffer_presenter_create(ANativeWindow* window) {
    if (!window) {
        ALOGE("Cannot create BufferManager with a null ANativeWindow.");
        return nullptr;
    }

    ASurfaceControl* surface_control = ASurfaceControl_createFromWindow(window, "BufferManagerSurfaceControl");
    if (!surface_control) {
        ALOGE("Failed to create ASurfaceControl from window.");
        return nullptr;
    }

    BufferManager* manager = new (std::nothrow) BufferManager();
    if (!manager) {
        ALOGE("Failed to allocate memory for BufferManager.");
        ASurfaceControl_release(surface_control);
        return nullptr;
    }

    manager->surface_control = surface_control;

    ALOGI("BufferManager created for window %p with SurfaceControl %p", window, surface_control);
    return manager;
}

void buffer_presenter_destroy(BufferManager* manager) {
    if (!manager) {
        return;
    }

    if (manager->surface_control) {
        ALOGI("Releasing ASurfaceControl");
        ASurfaceControl_release(manager->surface_control);
        manager->surface_control = nullptr;
    }
    
    delete manager;
    ALOGI("BufferManager destroyed.");
}

void buffer_presenter_send_buffer(BufferManager* manager,
                               AHardwareBuffer* buffer,
                               int acquire_fence_fd,
                               BufferManager_OnReleaseCallback on_release_callback,
                               void* context) {
    if (manager->surface_control == nullptr) {
        ALOGE("ASurfaceControl is null");
         // We are now responsible for the fence fd.
        if (acquire_fence_fd >= 0) {
            close(acquire_fence_fd);
        }
        return;
    }

    if (!buffer) {
        ALOGE("Input AHardwareBuffer is null.");
         // We are now responsible for the fence fd.
        if (acquire_fence_fd >= 0) {
            close(acquire_fence_fd);
        }
        return;
    }

    ASurfaceTransaction* transaction = ASurfaceTransaction_create();
    if (!transaction) {
        ALOGE("Failed to create ASurfaceTransaction.");
         // We are now responsible for the fence fd.
        if (acquire_fence_fd >= 0) {
            close(acquire_fence_fd);
        }
        return;
    }

    // TODO: When termux upgrades ndk-sysroot to r28
    /*if (android_get_device_api_level() > __ANDROID_API_V__)
        if (on_release_callback) {
            ASurfaceTransaction_setBufferWithRelease(
                transaction, manager->surface_control, buffer, acquire_fence_fd,
                context, on_release_callback);
        } else {
            // If no callback is needed, use the simpler function.
            ASurfaceTransaction_setBuffer(transaction, manager->surface_control, buffer, acquire_fence_fd);
        }
    else {*/
        ASurfaceTransaction_setBuffer(transaction, manager->surface_control, buffer, acquire_fence_fd);
        if (on_release_callback) {
            // We must allocate a temporary context to pass user callback and context.
            OnCompleteContext* callback_context = new (std::nothrow) OnCompleteContext{
                .user_callback = on_release_callback, 
                .user_context = context,
            };
            if (callback_context) {
                ASurfaceTransaction_setOnComplete(transaction, callback_context, on_complete_pre_api36);
            } else {
                ALOGE("Failed to allocate memory for OnCompleteContext wrapper.");
                // We can't set the callback, but we can still try to apply the transaction below.
            }
        }
    //}

    ASurfaceTransaction_apply(transaction);
    ASurfaceTransaction_delete(transaction);
}
