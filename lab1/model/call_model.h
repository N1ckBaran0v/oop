#ifndef __CALL_MODEL_H__
#define __CALL_MODEL_H__

#include "model.h"

enum funcs_name_t {MODEL_LOAD, MODEL_SAVE, MODEL_ROTATE, MODEL_SCALING, MODEL_MOVE, MODEL_DRAW, MODEL_DESTROY};

struct params_t {
    funcs_name_t action;
    union {
        const char *filename;
        const vector_t *offset;
        const rotate_params_t *rotate_params;
        const scaling_params_t *scaling_params;
        const scene_t *scene;
    };
};

return_code_t call_model(const params_t *params);

#endif // __CALL_MODEL_H__