#include <android/surface_control_input_receiver.h>

/**
 * @brief An opaque struct holding the state for the input receiver.
 */
typedef struct InputReceiver InputReceiver;

void input_receiver_destroy(InputReceiver* receiver);

InputReceiver* input_receiver_create(ANativeWindow* window,
                        AInputTransferToken* hostInputTransferToken,
                        ALooper* aLooper);