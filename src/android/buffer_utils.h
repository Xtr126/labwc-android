#include <android/hardware_buffer.h>
#include <android/native_window.h>
#include <drm_fourcc.h>
#include "buffer_presenter.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <wlr/render/dmabuf.h>
#include <wlr/types/wlr_output.h>

uint32_t android_to_drm_format(uint32_t android_format);

bool AHardwareBuffer_getDmabufAttributes(AHardwareBuffer *ahb, 
                           struct wlr_dmabuf_attributes *attribs);


/* timeout in msecs */
int sync_wait(int fd, int timeout);

void ANativeWindow_sendWlrBuffer(struct wlr_buffer *wlr_buffer, BufferManager *buffer_presenter);

#ifdef __cplusplus
}
#endif


