#include "android_output.h"

struct android_callbacks  {
	void *data;
	
	void (*view_add)(struct view *view);
	void (*view_remove)(struct view *view);
	void (*view_commit)(struct view *view);

	void (*output_commit)(struct wlr_buffer *buffer, struct output *output);
	void (*output_init)(struct output *output);
	void (*output_destroy)(struct output *output);
};