#include "cros_gralloc_handle.h"

extern "C" {
	#include <wlr/util/log.h>
	#include <wlr/render/swapchain.h>
	#include <wlr/render/allocator.h>
	#include <wlr/render/dmabuf.h>
}

#include "cros_gralloc_util.h"

static void log_cros_gralloc_handle_alt(const struct cros_gralloc_handle_alt *handle) {
	wlr_log(WLR_DEBUG, "usage: 0x%x", handle->usage);
	wlr_log(WLR_DEBUG, "reserved_region_size: %lu", handle->reserved_region_size);
	wlr_log(WLR_DEBUG, "total_size: %lu", handle->total_size);

	for (uint32_t i = 0; i < (handle->numFds); ++i) {
		wlr_log(WLR_DEBUG, "Plane %u:", i);
		wlr_log(WLR_DEBUG, "  fd: %d", handle->fds[i]);
		wlr_log(WLR_DEBUG, "  stride: %u", handle->strides[i]);
		wlr_log(WLR_DEBUG, "  offset: %u", handle->offsets[i]);
		wlr_log(WLR_DEBUG, "  size: %u", handle->sizes[i]);
	}

	if (handle->reserved_region_size > 0) {
		int meta_fd_index = handle->num_planes;
		wlr_log(WLR_DEBUG, "Metadata reserved region FD: %d", handle->fds[meta_fd_index]);
	}
}

void log_cros_gralloc_handle(const struct cros_gralloc_handle *handle) {
	wlr_log(WLR_DEBUG, "=== cros_gralloc_handle ===");
	wlr_log(WLR_DEBUG, "id: %u", handle->id);
	wlr_log(WLR_DEBUG, "width: %u, height: %u", handle->width, handle->height);
	wlr_log(WLR_DEBUG, "format: 0x%x (DRM), droid_format: %d", handle->format, handle->droid_format);
	wlr_log(WLR_DEBUG, "tiling: %u", handle->tiling);
	wlr_log(WLR_DEBUG, "format_modifier: 0x%lx", handle->format_modifier);
	wlr_log(WLR_DEBUG, "use_flags: 0x%lx", handle->use_flags);
	wlr_log(WLR_DEBUG, "magic: 0x%x", handle->magic);
	wlr_log(WLR_DEBUG, "pixel_stride: %u", handle->pixel_stride);
	wlr_log(WLR_DEBUG, "num_planes: %u", handle->num_planes);

    if (handle->num_planes > DRV_MAX_PLANES) {
		wlr_log(WLR_ERROR, "Invalid num_planes: %d\nFalling to 32-bit usage data type from older minigbm", handle->num_planes);
        log_cros_gralloc_handle_alt((cros_gralloc_handle_alt*)handle);
	} else {
        wlr_log(WLR_DEBUG, "usage: 0x%lx", handle->usage);
        wlr_log(WLR_DEBUG, "reserved_region_size: %lu", handle->reserved_region_size);
        wlr_log(WLR_DEBUG, "total_size: %lu", handle->total_size);
    
        for (uint32_t i = 0; i < (handle->numFds); ++i) {
            wlr_log(WLR_DEBUG, "Plane %u:", i);
            wlr_log(WLR_DEBUG, "  fd: %d", handle->fds[i]);
            wlr_log(WLR_DEBUG, "  stride: %u", handle->strides[i]);
            wlr_log(WLR_DEBUG, "  offset: %u", handle->offsets[i]);
            wlr_log(WLR_DEBUG, "  size: %u", handle->sizes[i]);
        }
    
        if (handle->reserved_region_size > 0) {
            int meta_fd_index = handle->num_planes;
            wlr_log(WLR_DEBUG, "Metadata reserved region FD: %d", handle->fds[meta_fd_index]);
        }
    }

	wlr_log(WLR_DEBUG, "=== End of cros_gralloc_handle ===");
}

static struct wlr_dmabuf_attributes cros_gralloc_to_wlr_dmabuf_alt(const struct cros_gralloc_handle_alt *handle) {
    struct wlr_dmabuf_attributes attribs = {
        .width = static_cast<int32_t>(handle->width),
        .height = static_cast<int32_t>(handle->height),
        .format = handle->format,
        .modifier = handle->format_modifier,
        .n_planes = static_cast<int>(handle->num_planes),
    };

    for (int i = 0; i < handle->num_planes; i++) {
        attribs.fd[i] = handle->fds[i];
        attribs.stride[i] = handle->strides[i];
        attribs.offset[i] = handle->offsets[i];
    }
    return attribs;
}
struct wlr_dmabuf_attributes cros_gralloc_to_wlr_dmabuf(const struct cros_gralloc_handle *handle) {

	if (handle->num_planes > DRV_MAX_PLANES) {
		wlr_log(WLR_ERROR, "Invalid num_planes: %d\nFalling to 32-bit usage data type from older minigbm", handle->num_planes);
        return cros_gralloc_to_wlr_dmabuf_alt((cros_gralloc_handle_alt*)handle);
	} else {
        struct wlr_dmabuf_attributes attribs = {
            .width = static_cast<int32_t>(handle->width),
            .height = static_cast<int32_t>(handle->height),
            .format = handle->format,
            .modifier = handle->format_modifier,
            .n_planes = static_cast<int>(handle->num_planes),
        };
    
        for (int i = 0; i < handle->num_planes; i++) {
            attribs.fd[i] = handle->fds[i];
            attribs.stride[i] = handle->strides[i];
            attribs.offset[i] = handle->offsets[i];
        }
        return attribs;
    }

}
