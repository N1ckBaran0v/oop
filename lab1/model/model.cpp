#include <stddef.h>
#include <stdlib.h>
#include <math.h>

#include "dot.h"
#include "errors.h"
#include "model.h"
#include "segment.h"

static return_code_t model_tmp_read(model_t *model_tmp, FILE *fin);

static return_code_t segments_check(const segment_arr_t *seg_arr, const dot_arr_t *dot_arr);

static return_code_t model_write(const model_t *model, FILE *fout);

model_t model_init(void) {
    model_t model;

    model.dots = dot_arr_init();
    model.segments = segment_arr_init();
    model.center = dot_init();

    return model;
}

return_code_t model_load(model_t *model, const char *filename) {
    if (model == NULL) {
        return ERR_PARAM_MODEL_NULLPTR;
    }
    if (filename == NULL) {
        return ERR_PARAM_FILENAME_NULLPTR;
    }

    return_code_t rc = ERR_OK;
    FILE *fin = fopen(filename, "r");

    if (fin == NULL) {
        rc = ERR_FILE_OPEN;
    }
    else {
        model_t tmp_model = model_init();
        rc = model_tmp_read(&tmp_model, fin);
        fclose(fin);
        if (rc == ERR_OK) {
            model_destroy(model);
            *model = tmp_model;
        }
    }
    
    return rc;
}

return_code_t model_save(const model_t *model, const char *filename) {
    if (model == NULL) {
        return ERR_PARAM_MODEL_NULLPTR;
    }
    if (filename == NULL) {
        return ERR_PARAM_FILENAME_NULLPTR;
    }

    return_code_t rc = ERR_OK;
    FILE *fout = fopen(filename, "w");

    if (fout == NULL) {
        rc = ERR_FILE_OPEN;
    }
    else {
        rc = model_write(model, fout);
        fclose(fout);
    }
    
    return rc;
}

return_code_t model_move(model_t *model, const vector_t *offset) {
    if (model == NULL) {
        return ERR_PARAM_MODEL_NULLPTR;
    }
    if (offset == NULL) {
        return ERR_PARAM_VECTOR_NULLPTR;
    }

    return_code_t rc = dot_move(&(model->center), offset);
    if (rc == ERR_OK) {
        rc = dot_arr_move(&(model->dots), offset);
    }

    return rc;
}

return_code_t model_scaling(model_t *model, const scaling_params_t *scaling_params) {
    if (model == NULL) {
        return ERR_PARAM_MODEL_NULLPTR;
    }
    if (scaling_params == NULL) {
        return ERR_PARAM_SCALING_NULLPTR;
    }

    return dot_arr_scaling(&(model->dots), &(model->center), scaling_params);
}

return_code_t model_rotate(model_t *model, const rotate_params_t *rotate_params) {
    if (model == NULL) {
        return ERR_PARAM_MODEL_NULLPTR;
    }
    if (rotate_params == NULL) {
        return ERR_PARAM_SCALING_NULLPTR;
    }

    return dot_arr_rotate(&(model->dots), &(model->center), rotate_params);
}

return_code_t model_draw(const model_t *model, const scene_t *scene) {
    if (model == NULL) {
        return ERR_PARAM_MODEL_NULLPTR;
    }
    if (scene == NULL) {
        return ERR_PARAM_SCENE_NULLPTR;
    }

    return segment_arr_draw(&(model->segments), &(model->dots), scene);
}

void model_destroy(model_t *model) {
    if (model == NULL) {
        return;
    }

    dot_arr_destroy(&(model->dots));
    segment_arr_destroy(&(model->segments));
}

static return_code_t model_tmp_read(model_t *model_tmp, FILE *fin) {
    if (model_tmp == NULL) {
        return ERR_PARAM_MODEL_NULLPTR;
    }
    if (fin == NULL) {
        return ERR_PARAM_FILE_NULLPTR;
    }

    return_code_t rc = dot_read(&(model_tmp->center), fin);
    if (rc == ERR_OK) {
        rc = dot_arr_read(&(model_tmp->dots), fin);
    }
    if (rc == ERR_OK) {
        model_tmp->segments = segment_arr_init();
        rc = segment_arr_read(&(model_tmp->segments), fin);
        if (rc == ERR_OK) {
            rc = segments_check(&(model_tmp->segments), &(model_tmp->dots));
        }
        if (rc != ERR_OK) {
            dot_arr_destroy(&(model_tmp->dots));
            segment_arr_destroy(&(model_tmp->segments));
        }
    }

    return rc;
}

static return_code_t segments_check(const segment_arr_t *seg_arr, const dot_arr_t *dot_arr) {
    if (seg_arr == NULL) {
        return ERR_PARAM_SEGMENT_ARR_NULLPTR;
    }
    if (dot_arr == NULL) {
        return ERR_PARAM_DOT_ARR_NULLPTR;
    }

    return segment_arr_check(seg_arr, dot_arr->size);
}

static return_code_t model_write(const model_t *model, FILE *fout) {
    if (model == NULL) {
        return ERR_PARAM_MODEL_NULLPTR;
    }
    if (fout == NULL) {
        return ERR_PARAM_FILE_NULLPTR;
    }

    return_code_t rc = dot_write(&(model->center), fout);
    if (rc == ERR_OK) {
        rc = dot_arr_write(&(model->dots), fout);
    }
    if (rc == ERR_OK) {
        rc = segment_arr_write(&(model->segments), fout);
    }

    return rc;
}
