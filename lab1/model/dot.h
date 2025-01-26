#ifndef __DOT_H__
#define __DOT_H__

#include <stdio.h>
#include <stddef.h>

#include "dot_and_vector.h"
#include "vector.h"
#include "errors.h"
#include "size.h"

struct dot_arr_t {
    size_t size;
    dot_t *arr;
};

dot_t dot_init(void);

dot_arr_t dot_arr_init(void);

return_code_t dot_read(dot_t *dot, FILE *fin);

return_code_t dot_arr_read(dot_arr_t *dot_arr, FILE *fin);

return_code_t dot_write(const dot_t *dot, FILE *fout);

return_code_t dot_arr_write(const dot_arr_t *dot_arr, FILE *fout);

return_code_t dot_move(dot_t *dot, const vector_t *offset);

return_code_t dot_arr_move(dot_arr_t *dot_arr, const vector_t *offset);

return_code_t dot_scaling(dot_t *dot_arr, const dot_t *center, const scaling_params_t *scaling_params);

return_code_t dot_arr_scaling(dot_arr_t *dot_arr, const dot_t *center, const scaling_params_t *scaling_params);

return_code_t dot_rotate(dot_t *dot, const dot_t *center, const rotate_params_t *rotate_params);

return_code_t dot_arr_rotate(dot_arr_t *dot, const dot_t *center, const rotate_params_t *rotate_params);

void dot_arr_destroy(dot_arr_t *dot_arr);

#endif //__DOT_H__