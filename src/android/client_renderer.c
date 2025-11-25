#include <wlr/render/wlr_renderer.h>
#include <wlr/types/wlr_buffer.h>

bool render_client_buffer_to_buffer(struct wlr_renderer *renderer,
        struct wlr_buffer *src_buffer, struct wlr_buffer *dst_buffer) {
    // Get the client buffer and its texture
    struct wlr_client_buffer *client_buffer = wlr_client_buffer_get(src_buffer);
    if (client_buffer == NULL || client_buffer->texture == NULL) {
        return false;
    }
    struct wlr_texture *texture = client_buffer->texture;

    // Start a render pass on the destination buffer
    struct wlr_buffer_pass_options pass_options = {0};
    struct wlr_render_pass *render_pass = wlr_renderer_begin_buffer_pass(renderer,
        dst_buffer, &pass_options);
    if (render_pass == NULL) {
        return false;
    }

    // Set up texture rendering options
    struct wlr_render_texture_options texture_options = {
        .texture = texture,
        .src_box = {0, 0}, // Default full texture
        .dst_box = {0, 0}, // Will be set to destination buffer size
        .alpha = 0,  // Opaque
        .clip = NULL,   // No clipping
        .transform = WL_OUTPUT_TRANSFORM_NORMAL,
        .filter_mode = WLR_SCALE_FILTER_BILINEAR, // Common default
        .blend_mode = WLR_RENDER_BLEND_MODE_PREMULTIPLIED,
    };

    // Use the destination buffer's dimensions
    texture_options.dst_box.width = dst_buffer->width;
    texture_options.dst_box.height = dst_buffer->height;

    // Render the texture
    wlr_render_pass_add_texture(render_pass, &texture_options);

    // Submit the render pass
    return wlr_render_pass_submit(render_pass);
}