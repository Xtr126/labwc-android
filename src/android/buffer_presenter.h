#pragma once

#include <android/native_window.h>
#include <android/hardware_buffer.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief An opaque struct holding the state for the buffer manager.
 * The internal implementation is hidden from the C interface.
 */
typedef struct BufferManager BufferManager;

/**
 * Based on ASurfaceTransaction_OnBufferRelease from AOSP
 * The ASurfaceTransaction_OnBufferRelease callback is invoked when a buffer that was passed in
 * ASurfaceTransaction_setBuffer is ready to be reused.
 *
 * This callback is guaranteed to be invoked if ASurfaceTransaction_setBuffer is called with a non
 * null buffer. If the buffer in the transaction is replaced via another call to
 * ASurfaceTransaction_setBuffer, the callback will be invoked immediately. Otherwise the callback
 * will be invoked before the ASurfaceTransaction_OnComplete callback after the buffer was
 * presented.
 *
 * If this callback is set, caller should not release the buffer using the
 * ASurfaceTransaction_OnComplete.
 *
 * \param context Optional context provided by the client that is passed into the callback.
 *
 * \param release_fence_fd Returns the fence file descriptor used to signal the release of buffer
 * associated with this callback. If this fence is valid (>=0), the buffer has not yet been released
 * and the fence will signal when the buffer has been released. If the fence is -1 , the buffer is
 * already released. The recipient of the callback takes ownership of the fence fd and is
 * responsible for closing it.
 *
 * THREADING
 * The callback can be invoked on any thread.
 *
 * Available since API level 36.
 */ 
typedef void (*BufferManager_OnReleaseCallback)(void* _Null_unspecified context,
                                                    int release_fence_fd);


/**
 * @brief Creates a new BufferManager instance.
 *
 * This function creates an ASurfaceControl from the provided ANativeWindow
 * and initializes the necessary components to manage transactions.
 *
 * @param window The ANativeWindow to which buffers will be sent. The caller
 * retains ownership of the window and must ensure its lifetime
 * exceeds that of the BufferManager.
 * @return A pointer to the newly created BufferManager, or NULL on failure.
 */
BufferManager* _Nullable buffer_presenter_create(ANativeWindow* _Nonnull window);

/**
 * @brief Destroys a BufferManager instance and cleans up its resources.
 *
 * This function releases the underlying ASurfaceControl.
 *
 * @param manager A pointer to the BufferManager instance to be destroyed.
 * If manager is NULL, the function does nothing.
 */
void buffer_presenter_destroy(BufferManager* _Nonnull manager);

/**
 * @brief Sends a hardware buffer to the associated ANativeWindow using ASurfaceTransaction.
 *
 * This function creates and applies a transaction to set the provided buffer
 * on the window's ASurfaceControl. It registers a callback to be fired when the
 * previously displayed buffer is ready for reuse.
 *
 * @param manager The BufferManager instance.
 * @param buffer The AHardwareBuffer to display.
 * @param acquire_fence_fd A file descriptor for a sync fence that will signal
 * when the buffer is ready to be read. The transaction will wait
 * on this fence. The function takes ownership of the fd and will
 * close it. Use -1 if no fence is needed.
 * @param on_release_callback A callback function to be invoked when the previously
 * displayed buffer is released. Can be NULL if no notification is needed.
 * @param context A user-defined pointer that will be passed to the on_release_callback.
 * @return 0 on success, or a negative value on error.
 */
void buffer_presenter_send_buffer(BufferManager* _Nonnull manager,
                               AHardwareBuffer* _Nonnull buffer,
                               int acquire_fence_fd,
                               BufferManager_OnReleaseCallback _Null_unspecified on_release_callback,
                               void* _Null_unspecified context);


#ifdef __cplusplus
}
#endif
