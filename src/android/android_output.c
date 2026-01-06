#include "ahb_wlr_allocator.h"
#include "client_renderer.h"
#include <assert.h>
#include <stdlib.h>
#include <wlr/util/log.h>
#include <wlr/types/wlr_compositor.h>
#include <wlr/types/wlr_scene.h>
#include <wlr/render/swapchain.h>
#include "labwc.h"
#include "android_output.h"

void android_output_present_buffer(struct wlr_scene_output *scene_output,
		struct wlr_output_state *state) 
{
	struct wlr_output *wlr_output = scene_output->output;
	struct output *output = wlr_output->data;

	if (output->buffer_presenter && output->ahb_swapchain) {
		struct wlr_scene_output_state_options options = {0};
		options.swapchain = output->ahb_swapchain;
		if (!wlr_scene_output_build_state(scene_output, state, &options)) {
			wlr_log(WLR_ERROR, "Failed to build output state for %s",
				wlr_output->name);
			return;
		}

		struct wlr_ahb_buffer *ahb_buffer = try_get_ahb_buffer_from_buffer(output->ahb_swapchain->slots[0].buffer);
		if (ahb_buffer) buffer_presenter_send_buffer(output->buffer_presenter, ahb_buffer->ahb, -1, NULL, NULL);
		else {
			wlr_log(WLR_ERROR, "Input buffer is not an Android buffer");
		} 
	} else {
		wlr_log(WLR_ERROR, "Something went wrong with rendering the scene onto an Android buffer");
	}
}

void android_view_present_buffer(struct view *view) {
	if (view->surface->buffer != NULL) {
		if (view->buffer_presenter != NULL) {
			struct wlr_buffer *src_buffer = &view->surface->buffer->base;
			struct wlr_buffer *dst_buffer = &view->android_buffer->base;
			render_client_buffer_to_buffer(view->server->renderer, src_buffer, dst_buffer);
			buffer_presenter_send_buffer(view->buffer_presenter, view->android_buffer->ahb, -1, NULL, NULL);
		} else {
			wlr_log(WLR_ERROR, "Something went wrong with presenting the buffer to Android");
		}
	} else {
		wlr_log(WLR_ERROR, "Something went wrong with uploading the buffer");
	}             
}

static bool wlr_drm_format_copy(struct wlr_drm_format *dst, const struct wlr_drm_format *src) {
	assert(src->len <= src->capacity);

	uint64_t *modifiers = (uint64_t *)malloc(sizeof(*modifiers) * src->len);
	if (!modifiers) {
		return false;
	}

	memcpy(modifiers, src->modifiers, sizeof(*modifiers) * src->len);

	wlr_drm_format_finish(dst);
	dst->capacity = src->len;
	dst->len = src->len;
	dst->format = src->format;
	dst->modifiers = modifiers;
	return true;
}


struct wlr_swapchain *android_swapchain_create_for_output(struct output *output) {
	struct wlr_swapchain *swapchain = (struct wlr_swapchain *)calloc(1, sizeof(*swapchain));
	if (swapchain == NULL) {
		return NULL;
	}
	swapchain->allocator = NULL;
	swapchain->width = output->wlr_output->width;
	swapchain->height = output->wlr_output->height;

	swapchain->format = (const struct wlr_drm_format){ AHB_FORMAT_PREFERRED_DRM };

	struct wlr_swapchain_slot *slot = &swapchain->slots[0];
	slot->acquired = false;
	slot->buffer = wlr_allocator_create_buffer(output->server->allocator, output->wlr_output->width, output->wlr_output->height, &swapchain->format);

	if (slot->buffer == NULL) {
		wlr_log(WLR_ERROR, "Failed to create AHB swapchain");
		free(swapchain);
		return NULL;
	}

	wlr_log(WLR_DEBUG, "AHB swapchain created");
	return swapchain;
}
