#include <assert.h>
#include <stdlib.h>
#include <wlr/interfaces/wlr_buffer.h>
#include <wlr/util/log.h>
#include "ahb_wlr_allocator.h"
#include <wlr/render/drm_format_set.h>

static const struct wlr_buffer_impl buffer_impl;

struct wlr_ahb_buffer *get_ahb_buffer_from_buffer(struct wlr_buffer *wlr_buffer) {
	assert(wlr_buffer->impl == &buffer_impl);
	struct wlr_ahb_buffer *buffer = wl_container_of(wlr_buffer, buffer, base);
	return buffer;
}

static struct wlr_ahb_buffer *create_buffer(struct wlr_ahb_allocator *alloc,
		int width, int height, const struct wlr_drm_format *format) {
	assert(format->format == AHB_FORMAT_PREFERRED_DRM);
	struct wlr_ahb_buffer *buffer = calloc(1, sizeof(*buffer));
	if (buffer == NULL) {
		return NULL;
	}

	AHardwareBuffer_Desc desc = {
        .width = width,
        .height = height,
        .layers = 1, // Single layer
        .format = AHB_FORMAT_PREFERRED, 
        .usage = AHARDWAREBUFFER_USAGE_GPU_SAMPLED_IMAGE | 
				AHARDWAREBUFFER_USAGE_COMPOSER_OVERLAY | 
				AHARDWAREBUFFER_USAGE_GPU_FRAMEBUFFER
    };

	AHardwareBuffer_allocate(&desc, &buffer->ahb);
	wlr_buffer_init(&buffer->base, &buffer_impl,
		width, height);

	if (!AHardwareBuffer_getDmabufAttributes(buffer->ahb, &buffer->dmabuf)) {
		wlr_log(WLR_ERROR, "Failed to get dmabuf attributes from AHardwareBuffer");
	    AHardwareBuffer_release(buffer->ahb);
		free(buffer);
		return NULL;
	}
	
	return buffer;

}

static void buffer_destroy(struct wlr_buffer *wlr_buffer) {
    struct wlr_ahb_buffer *buffer = get_ahb_buffer_from_buffer(wlr_buffer);
    AHardwareBuffer_release(buffer->ahb);
    free(buffer);
}

static bool buffer_get_dmabuf(struct wlr_buffer *wlr_buffer,
		struct wlr_dmabuf_attributes *attribs) {
    struct wlr_ahb_buffer *buffer = get_ahb_buffer_from_buffer(wlr_buffer);
	*attribs = buffer->dmabuf;
    return true;
}

static const struct wlr_buffer_impl buffer_impl = {
	.destroy = buffer_destroy,
	.get_dmabuf = buffer_get_dmabuf,
};

static const struct wlr_allocator_interface allocator_impl;

static struct wlr_ahb_allocator *get_ahb_alloc_from_alloc(
		struct wlr_allocator *wlr_alloc) {
	assert(wlr_alloc->impl == &allocator_impl);
	struct wlr_ahb_allocator *alloc = wl_container_of(wlr_alloc, alloc, base);
	return alloc;
}

struct wlr_allocator *wlr_ahb_allocator_create() {

	struct wlr_ahb_allocator *alloc = calloc(1, sizeof(*alloc));
	if (alloc == NULL) {
		return NULL;
	}
	wlr_allocator_init(&alloc->base, &allocator_impl, WLR_BUFFER_CAP_DMABUF);

	wl_list_init(&alloc->buffers);


	wlr_log(WLR_DEBUG, "Created AHardwareBuffer based allocator with backend");
	return &alloc->base;
}

static void allocator_destroy(struct wlr_allocator *wlr_alloc) {
	struct wlr_ahb_allocator *alloc = get_ahb_alloc_from_alloc(wlr_alloc);

	struct wlr_ahb_buffer *buf, *buf_tmp;
	wl_list_for_each_safe(buf, buf_tmp, &alloc->buffers, link) {
		AHardwareBuffer_release(buf->ahb);
		buf->ahb = NULL;
		wl_list_remove(&buf->link);
		wl_list_init(&buf->link);
	}
	free(alloc);
}

static struct wlr_buffer *allocator_create_buffer(
		struct wlr_allocator *wlr_alloc, int width, int height,
		const struct wlr_drm_format *format) {
	struct wlr_ahb_allocator *alloc = get_ahb_alloc_from_alloc(wlr_alloc);
	struct wlr_ahb_buffer *buffer = create_buffer(alloc, width, height, format);
	if (buffer == NULL) {
		return NULL;
	}
	return &buffer->base;
}

static const struct wlr_allocator_interface allocator_impl = {
	.destroy = allocator_destroy,
	.create_buffer = allocator_create_buffer,
};
