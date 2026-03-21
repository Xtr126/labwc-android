#include "client_renderer.h"
#include "labwc.h"
#include <time.h>
#include <wlr/types/wlr_scene.h>

static void
render_node(struct server *server, struct wlr_render_pass *pass,
		struct wlr_scene_node *node, int x, int y)
{
	switch (node->type) {
	case WLR_SCENE_NODE_TREE: {
		struct wlr_scene_tree *tree = wlr_scene_tree_from_node(node);
		struct wlr_scene_node *child;
		wl_list_for_each(child, &tree->children, link) {
			render_node(server, pass, child, x + node->x, y + node->y);
		}
		break;
	}
	case WLR_SCENE_NODE_BUFFER: {
		struct wlr_scene_buffer *scene_buffer =
			wlr_scene_buffer_from_node(node);
		if (!scene_buffer->buffer) {
			break;
		}
		struct wlr_texture *texture = wlr_texture_from_buffer(
			server->renderer, scene_buffer->buffer);
		if (!texture) {
			break;
		}
		wlr_render_pass_add_texture(pass, &(struct wlr_render_texture_options){
			.texture = texture,
			.src_box = scene_buffer->src_box,
			.dst_box = {
				.x = x,
				.y = y,
				.width = scene_buffer->dst_width,
				.height = scene_buffer->dst_height,
			},
			.transform = scene_buffer->transform,
		});
		wlr_texture_destroy(texture);
		break;
	}
	case WLR_SCENE_NODE_RECT:
		/* should be unreached */
		wlr_log(WLR_ERROR, "ignoring rect");
		break;
	}
}

bool render_view_to_buffer(struct view *view, struct wlr_buffer *dst_buffer) {
    struct wlr_renderer* renderer = view->server->renderer;
    // Start a render pass on the destination buffer
    struct wlr_render_pass *render_pass = wlr_renderer_begin_buffer_pass(renderer,
        dst_buffer, NULL);
    
    render_node(view->server, render_pass, &view->content_tree->node, 0, 0);

    // Submit the render pass
    if (!wlr_render_pass_submit(render_pass)) {
		wlr_log(WLR_ERROR, "failed to submit render pass");
		return false;
	}
    return true;
}