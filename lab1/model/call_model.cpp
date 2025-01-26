#include "call_model.h"
#include "errors.h"

return_code_t call_model(const params_t *params) {
    if (params == NULL) {
        return ERR_PARAM_PARAMS_NULLPTR;
    }

    return_code_t rc = ERR_OK;
    static model_t model = model_init();
    
    if (params->action == MODEL_LOAD) {
        rc = model_load(&model, params->filename);
    }
    else if (params->action == MODEL_SAVE) {
        rc = model_save(&model, params->filename); 
    }
    else if (params->action == MODEL_MOVE) {
        rc = model_move(&model, params->offset);
    }
    else if (params->action == MODEL_ROTATE) {
        rc = model_rotate(&model, params->rotate_params);
    }
    else if (params->action == MODEL_SCALING) {
        rc = model_scaling(&model, params->scaling_params);
    }
    else if (params->action == MODEL_DRAW) {
        rc = model_draw(&model, params->scene);
    }
    else if (params->action == MODEL_DESTROY) {
        model_destroy(&model);
    }
    else {
        rc = ERR_ACTION_INVALID;
    }
    
    return rc;
}
