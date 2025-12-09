#include <android/hardware_buffer.h>
#include <wlr/types/wlr_buffer.h>
#include <wlr/render/allocator.h>
#include "buffer_utils.h"

#define AHB_FORMAT_PREFERRED AHARDWAREBUFFER_FORMAT_R8G8B8X8_UNORM
#define AHB_FORMAT_PREFERRED_DRM android_to_drm_format(AHB_FORMAT_PREFERRED)

struct wlr_ahb_buffer {
	struct wlr_buffer base;
	struct wlr_dmabuf_attributes dmabuf;
	AHardwareBuffer *ahb;
	struct wl_list link; // wlr_ahb_allocator.buffers
};

struct wlr_ahb_allocator {
	struct wlr_allocator base;

	struct wl_list buffers; // wlr_ahb_buffer.link
};

/**
 * Creates a new allocator for AHardwareBuffers.
 */
struct wlr_allocator *wlr_ahb_allocator_create();

struct wlr_ahb_buffer *get_ahb_buffer_from_buffer(struct wlr_buffer *wlr_buffer);