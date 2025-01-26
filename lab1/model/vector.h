#ifndef __VECTOR_H__
#define __VECTOR_H__

#include "dot_and_vector.h"
#include "errors.h"

return_code_t vector_create(vector_t *vector, const dot_t *start, const dot_t *end);

return_code_t end_dot_pos(dot_t *dst, const dot_t *center, const vector_t *offset);

return_code_t vector_scaling(vector_t *vector, const scaling_params_t *scaling_params);

return_code_t vector_rotate(vector_t *vector, const rotate_params_t *rotate_params);

#endif // __VECTOR_H__
