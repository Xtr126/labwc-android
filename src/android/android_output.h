#include "output.h"
#include "view.h"

void android_output_present_buffer(struct wlr_scene_output *scene_output,
		struct wlr_output_state *state);

void android_view_present_buffer(struct view *view);

struct wlr_swapchain *android_swapchain_create_for_output(struct output *output);