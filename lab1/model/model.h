#ifndef __MODEL_H__
#define __MODEL_H__

#include "dot_and_vector.h"
#include "errors.h"
#include "segment.h"
#include "size.h"

struct model_t {
    dot_arr_t dots;
    segment_arr_t segments;
    dot_t center;
};

model_t model_init(void);

return_code_t model_load(model_t *model, const char *filename);

return_code_t model_save(const model_t *model, const char *filename);

return_code_t model_move(model_t *model, const vector_t *offset);

return_code_t model_scaling(model_t *model, const scaling_params_t *scaling_params);

return_code_t model_rotate(model_t *model, const rotate_params_t *rotate_params);

return_code_t model_draw(const model_t *model, const scene_t *scene);

void model_destroy(model_t *model);

#endif // __MODEL_H__