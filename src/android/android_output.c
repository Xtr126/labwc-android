#include "ahb_wlr_allocator.h"
#include "android_output.h"
#include "client_renderer.h"
#include <assert.h>
#include <wlr/util/log.h>
#include <wlr/types/wlr_compositor.h>
#include "labwc.h"

void android_output_present_buffer(struct wlr_buffer *buffer, struct output *output) {
	if (buffer && output->buffer_presenter) {
		struct wlr_ahb_buffer *ahb_buffer = try_get_ahb_buffer_from_buffer(buffer);
		if (ahb_buffer) buffer_presenter_send_buffer(output->buffer_presenter, ahb_buffer->ahb, -1, NULL, NULL);
		else  wlr_log(WLR_ERROR, "Input buffer is not an Android buffer");
	} else {
		wlr_log(WLR_ERROR, "Something went wrong with presenting the buffer to Android");
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