#include "ahb_wlr_allocator.h"
#include "android_output.h"

void android_output_present_buffer(struct wlr_buffer *buffer, struct output *output)
{
	if (buffer && output->buffer_presenter) {
		struct wlr_ahb_buffer *ahb_buffer = get_ahb_buffer_from_buffer(buffer);
		buffer_presenter_send_buffer(output->buffer_presenter, ahb_buffer->ahb, -1, NULL, NULL);
	}
}