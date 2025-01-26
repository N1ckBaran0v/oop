#include <stdlib.h>
#include <math.h>

#include "dot.h"
#include "errors.h"
#include "size.h"

static return_code_t dot_tmp_read(dot_t *dot_tmp, FILE *fin);

static dot_t *dots_alloc(const size_t nmemb);

static return_code_t dot_arr_tmp_read(dot_arr_t *dot_arr_tmp, FILE *fin);

static return_code_t dots_tmp_read(dot_t *dots_tmp, const size_t size, FILE *fin);

static return_code_t dots_write(const dot_t *dots, const size_t size, FILE *fout);

static return_code_t dots_move(dot_t *dots, const size_t size, const vector_t *offset);

static return_code_t dots_scaling(dot_t *dots, const size_t size, const dot_t *center, 
                                               const scaling_params_t *scaling_params);

static return_code_t dots_rotate(dot_t *dots, const size_t size, const dot_t *center, 
                                              const rotate_params_t *rotate_params);

dot_t dot_init(void) {
    dot_t dot;

    dot.x = 0;
    dot.y = 0;
    dot.z = 0;

    return dot;
}

dot_arr_t dot_arr_init(void) {
    dot_arr_t dot_arr;

    dot_arr.size = 0;
    dot_arr.arr = NULL;

    return dot_arr;
}

return_code_t dot_read(dot_t *dot, FILE *fin) {
    if (dot == NULL) {
        return ERR_PARAM_DOT_NULLPTR;
    }
    if (fin == NULL) {
        return ERR_PARAM_FILE_NULLPTR;
    }

    return_code_t rc = ERR_OK;
    dot_t tmp_dot;


    rc = dot_tmp_read(&tmp_dot, fin);
    if (rc == ERR_OK) {
        *dot = tmp_dot;
    }

    return rc;
}

return_code_t dot_arr_read(dot_arr_t *dot_arr, FILE *fin) {
    if (dot_arr == NULL) {
        return ERR_PARAM_DOT_ARR_NULLPTR;
    }
    if (fin == NULL) {
        return ERR_PARAM_FILE_NULLPTR;
    }

    return_code_t rc = ERR_OK;
    dot_arr_t tmp_dot_arr = dot_arr_init();

    rc = dot_arr_tmp_read(&tmp_dot_arr, fin);
    if (rc != ERR_OK) {
        dot_arr_destroy(&tmp_dot_arr);
    }
    else {
        dot_arr_destroy(dot_arr);
        *dot_arr = tmp_dot_arr;
    }

    return rc;
}

return_code_t dot_write(const dot_t *dot, FILE *fout) {
    if (dot == NULL) {
        return ERR_PARAM_DOT_NULLPTR;
    }
    if (fout == NULL) {
        return ERR_PARAM_FILE_NULLPTR;
    }

    fprintf(fout, "%lf %lf %lf\n", dot->x, dot->y, dot->z);

    return ERR_OK;
}

return_code_t dot_arr_write(const dot_arr_t *dot_arr, FILE *fout) {
    if (dot_arr == NULL) {
        return ERR_PARAM_DOT_ARR_NULLPTR;
    }
    if (fout == NULL) {
        return ERR_PARAM_FILE_NULLPTR;
    }

    return_code_t rc = size_write(dot_arr->size, fout);
    if (rc == ERR_OK) {
        rc = dots_write(dot_arr->arr, dot_arr->size, fout);
    }
    
    return rc;
}

return_code_t dot_move(dot_t *dot, const vector_t *offset) {
    if (dot == NULL) {
        return ERR_PARAM_DOT_NULLPTR;
    }
    if (offset == NULL) {
        return ERR_PARAM_VECTOR_NULLPTR;
    }

    dot->x += offset->x;
    dot->y += offset->y;
    dot->z += offset->z;

    return ERR_OK;
}

return_code_t dot_arr_move(dot_arr_t *dot_arr, const vector_t *offset) {
    if (dot_arr == NULL) {
        return ERR_PARAM_DOT_ARR_NULLPTR;
    }
    if (offset == NULL) {
        return ERR_PARAM_VECTOR_NULLPTR;
    }

    return dots_move(dot_arr->arr, dot_arr->size, offset);
}

return_code_t dot_scaling(dot_t *dot, const dot_t *center, const scaling_params_t *scaling_params) {
    if (dot == NULL || center == NULL) {
        return ERR_PARAM_DOT_NULLPTR;
    }
    if (scaling_params == NULL) {
        return ERR_PARAM_SCALING_NULLPTR;
    }
    if (fabs(scaling_params->kx) < EPS || fabs(scaling_params->ky) < EPS 
                                       || fabs(scaling_params->kz) < EPS) {
        return ERR_PARAM_SCALING_INVALID;
    }

    return_code_t rc = ERR_OK;
    vector_t scaling_vector;

    rc = vector_create(&scaling_vector, center, dot);
    if (rc == ERR_OK) {
        rc = vector_scaling(&scaling_vector, scaling_params);
    }
    if (rc == ERR_OK) {
        rc = end_dot_pos(dot, center, &scaling_vector);
    }
    
    return rc;
}

return_code_t dot_arr_scaling(dot_arr_t *dot_arr, const dot_t *center, const scaling_params_t *scaling_params) {
    if (dot_arr == NULL) {
        return ERR_PARAM_DOT_ARR_NULLPTR;
    }
    if (center == NULL) {
        return ERR_PARAM_DOT_NULLPTR;
    }
    if (scaling_params == NULL) {
        return ERR_PARAM_SCALING_NULLPTR;
    }
    if (fabs(scaling_params->kx) < EPS || fabs(scaling_params->ky) < EPS 
                                       || fabs(scaling_params->kz) < EPS) {
        return ERR_PARAM_SCALING_INVALID;
    }

    return dots_scaling(dot_arr->arr, dot_arr->size, center, scaling_params);
}

return_code_t dot_rotate(dot_t *dot, const dot_t *center, const rotate_params_t *rotate_params) {
    if (dot == NULL || center == NULL) {
        return ERR_PARAM_DOT_NULLPTR;
    }
    if (rotate_params == NULL) {
        return ERR_PARAM_ROTATE_NULLPTR;
    }

    return_code_t rc = ERR_OK;
    vector_t rotate_vector;

    rc = vector_create(&rotate_vector, center, dot);
    if (rc == ERR_OK) {
        rc = vector_rotate(&rotate_vector, rotate_params);
    }
    if (rc == ERR_OK) {
        rc = end_dot_pos(dot, center, &rotate_vector);
    }

    return rc;
}

return_code_t dot_arr_rotate(dot_arr_t *dot_arr, const dot_t *center, const rotate_params_t *rotate_params) {
    if (dot_arr == NULL) {
        return ERR_PARAM_DOT_ARR_NULLPTR;
    }
    if (center == NULL) {
        return ERR_PARAM_DOT_NULLPTR;
    }
    if (rotate_params == NULL) {
        return ERR_PARAM_ROTATE_NULLPTR;
    }

    return dots_rotate(dot_arr->arr, dot_arr->size, center, rotate_params);
}

void dot_arr_destroy(dot_arr_t *dot_arr) {
    if (dot_arr == NULL) {
        return;
    }

    dot_arr->size = 0;
    free(dot_arr->arr);
    dot_arr->arr = NULL;
}

static return_code_t dot_tmp_read(dot_t *dot_tmp, FILE *fin) {
    if (dot_tmp == NULL) {
        return ERR_PARAM_DOT_NULLPTR;
    }
    if (fin == NULL) {
        return ERR_PARAM_FILE_NULLPTR;
    }

    return_code_t rc = ERR_OK;
    if (fscanf(fin, "%lf %lf %lf", &(dot_tmp->x), &(dot_tmp->y), &(dot_tmp->z)) != 3) {
        rc = ERR_FILE_READ;
    }

    return rc;
}

static dot_t *dots_alloc(const size_t nmemb) {
    if (nmemb == 0)
        return NULL;

    return (dot_t*)calloc(nmemb, sizeof(dot_t));
}

static return_code_t dot_arr_tmp_read(dot_arr_t *dot_arr_tmp, FILE *fin) {
    if (dot_arr_tmp == NULL) {
        return ERR_PARAM_DOT_ARR_NULLPTR;
    }
    if (fin == NULL) {
        return ERR_PARAM_FILE_NULLPTR;
    }

    return_code_t rc = size_read(&(dot_arr_tmp->size), fin);
    if (rc == ERR_OK) {
        dot_arr_tmp->arr = dots_alloc(dot_arr_tmp->size);
        if (dot_arr_tmp->arr == NULL) {
            rc = ERR_MEM_ALLOC;
        }
    }
    if (rc == ERR_OK) {
        rc = dots_tmp_read(dot_arr_tmp->arr, dot_arr_tmp->size, fin);
    }

    return rc;
}

static return_code_t dots_tmp_read(dot_t *dots_tmp, const size_t size, FILE *fin) {
    if (dots_tmp == NULL) {
        return ERR_PARAM_DOT_NULLPTR;
    }
    if (fin == NULL) {
        return ERR_PARAM_FILE_NULLPTR;
    }

    return_code_t rc = ERR_OK;

    for (size_t i = 0; rc == ERR_OK && i < size; ++i) {
        rc = dot_tmp_read(dots_tmp + i, fin);
    }

    return rc;
}

static return_code_t dots_write(const dot_t *dots, const size_t size, FILE *fout) {
    if (dots == NULL) {
        return ERR_PARAM_DOT_NULLPTR;
    }
    if (fout == NULL) {
        return ERR_PARAM_FILE_NULLPTR;
    }

    return_code_t rc = ERR_OK;

    for (size_t i = 0; rc == ERR_OK && i < size; ++i) {
        rc = dot_write(dots + i, fout);
    }

    return rc;
}

static return_code_t dots_move(dot_t *dots, const size_t size, const vector_t *offset) {
    if (dots == NULL) {
        return ERR_PARAM_DOT_NULLPTR;
    }
    if (offset == NULL) {
        return ERR_PARAM_VECTOR_NULLPTR;
    }

    return_code_t rc = ERR_OK;

    for (size_t i = 0; rc == ERR_OK && i < size; ++i) {
        rc = dot_move(dots + i, offset);
    }

    return rc;
}

static return_code_t dots_scaling(dot_t *dots, const size_t size, const dot_t *center, 
                                               const scaling_params_t *scaling_params) {
    if (dots == NULL || center == NULL) {
        return ERR_PARAM_DOT_NULLPTR;
    }
    if (scaling_params == NULL) {
        return ERR_PARAM_SCALING_NULLPTR;
    }
    if (fabs(scaling_params->kx) < EPS || fabs(scaling_params->ky) < EPS 
                                       || fabs(scaling_params->kz) < EPS) {
        return ERR_PARAM_SCALING_INVALID;
    }

    return_code_t rc = ERR_OK;

    for (size_t i = 0; rc == ERR_OK && i < size; ++i) {
        rc = dot_scaling(dots + i, center, scaling_params);
    }

    return rc;
}

static return_code_t dots_rotate(dot_t *dots, const size_t size, const dot_t *center, 
                                              const rotate_params_t *rotate_params) {
    if (dots == NULL || center == NULL) {
        return ERR_PARAM_DOT_NULLPTR;
    }
    if (rotate_params == NULL) {
        return ERR_PARAM_ROTATE_NULLPTR;
    }

    return_code_t rc = ERR_OK;

    for (size_t i = 0; rc == ERR_OK && i < size; ++i) {
        rc = dot_rotate(dots + i, center, rotate_params);
    }

    return rc;
}

