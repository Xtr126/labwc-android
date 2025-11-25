#include "input_receiver.h"

#include <android/input_transfer_token_jni.h>
#include <android/looper.h>
#include <stdint.h>
#include <stdlib.h>
#include <wlr/util/log.h>
#define ALOGE(...) wlr_log(WLR_ERROR, __VA_ARGS__)
#define ALOGI(...) wlr_log(WLR_DEBUG, __VA_ARGS__)

// Context struct to hold data for our callbacks.
struct InputReceiverContext {
    int touchCount;
};

struct InputReceiver {
    AInputTransferToken* hostInputTransferToken;
    AInputReceiver* inputReceiver;
    AInputReceiverCallbacks* callbacks;
    ASurfaceControl* aSurfaceControl;
};

// Callback function for motion events.
bool onMotionEvent(void* context, AInputEvent* motionEvent) {
    struct InputReceiverContext* myContext = context;

    int32_t action = AMotionEvent_getAction(motionEvent);
    int32_t actionMasked = action & AMOTION_EVENT_ACTION_MASK;

    if (actionMasked == AMOTION_EVENT_ACTION_DOWN) {
        myContext->touchCount++;
        ALOGI("Touch down! Total touches: %d", myContext->touchCount);
    } else if (actionMasked == AMOTION_EVENT_ACTION_UP) {
        ALOGI("Touch up!");
    } else if (actionMasked == AMOTION_EVENT_ACTION_MOVE) {
        // You can get the coordinates and other info here
        float x = AMotionEvent_getX(motionEvent, 0);
        float y = AMotionEvent_getY(motionEvent, 0);
        ALOGI("Touch move at: (%f, %f)", x, y);
    }

    // Always release the event after processing.
    AInputEvent_release(motionEvent);

    // Return true to indicate that we've consumed the event.
    return true;
}

// Callback function for key events.
bool onKeyEvent(void* context, AInputEvent* keyEvent) {
    // This example doesn't use the key event context, but it's passed here.
    int32_t action = AKeyEvent_getAction(keyEvent);
    int32_t keyCode = AKeyEvent_getKeyCode(keyEvent);

    if (action == AKEY_EVENT_ACTION_DOWN) {
        ALOGI("Key down: %d", keyCode);
    } else if (action == AKEY_EVENT_ACTION_UP) {
        ALOGI("Key up: %d", keyCode);
    }

    // Always release the event.
    AInputEvent_release(keyEvent);

    return true;
}


void input_receiver_destroy(InputReceiver* receiver) {
    // Clean-up
    AInputTransferToken_release(receiver->hostInputTransferToken);    
    AInputReceiver_release(receiver->inputReceiver);
    AInputReceiverCallbacks_release(receiver->callbacks);
    ASurfaceControl_release(receiver->aSurfaceControl);
    free(receiver);
}

InputReceiver* input_receiver_create(ANativeWindow* window,
                        AInputTransferToken* hostInputTransferToken,
                        ALooper* aLooper) {
    ASurfaceControl* aSurfaceControl = ASurfaceControl_createFromWindow(window, "InputReceiverSurfaceControl");
    if (!aSurfaceControl) {
        ALOGE("Failed to create ASurfaceControl from window");
        return NULL;
    }

    // Create a context to pass to our callbacks.
    struct InputReceiverContext myContext;

    // Create the callbacks object.
    AInputReceiverCallbacks* callbacks = AInputReceiverCallbacks_create(&myContext);
    if (!callbacks) {
        ALOGE("Failed to create AInputReceiverCallbacks");
        AInputReceiverCallbacks_release(callbacks);
        ASurfaceControl_release(aSurfaceControl);
        return NULL;
    }
    
    // Set our callback functions.
    AInputReceiverCallbacks_setMotionEventCallback(callbacks, onMotionEvent);
    AInputReceiverCallbacks_setKeyEventCallback(callbacks, onKeyEvent);

    // Register the input receiver. We're using the unbatched version here.
    AInputReceiver* inputReceiver = AInputReceiver_createUnbatchedInputReceiver(
            aLooper,
            hostInputTransferToken,
            aSurfaceControl,
            callbacks);

    if (inputReceiver) {
        ALOGI("Input receiver successfully created");
    } else {
        ALOGE("Failed to create input receiver");
        return NULL;
    }

    InputReceiver *receiver = calloc(1, sizeof(*receiver));
    if (!receiver) {
        ALOGE("Failed to allocate memory for InputReceiver");
        return NULL;
    }


    receiver->hostInputTransferToken = hostInputTransferToken;
    receiver->inputReceiver = inputReceiver;
    receiver->callbacks = callbacks;
    receiver->aSurfaceControl = aSurfaceControl;

    return receiver;
}