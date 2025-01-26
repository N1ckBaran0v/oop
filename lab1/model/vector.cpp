#include <stddef.h>
#include <math.h>

#include "vector.h"

#define PI 3.1415927
#define MAX_DEGREES 360

static double radians(const double angle);

static return_code_t vector_rotate_x(vector_t *vector, const double angle);

static return_code_t vector_rotate_y(vector_t *vector, const double angle);

static return_code_t vector_rotate_z(vector_t *vector, const double angle);

return_code_t vector_create(vector_t *vector, const dot_t *start, const dot_t *end) {
    if (vector == NULL) {
        return ERR_PARAM_VECTOR_NULLPTR;
    }
    if (start == NULL || end == NULL) {
        return ERR_PARAM_DOT_NULLPTR;
    }

    vector->x = end->x - start->x;
    vector->y = end->y - start->y;
    vector->z = end->z - start->z;

    return ERR_OK;
}

return_code_t end_dot_pos(dot_t *dst, const dot_t *center, const vector_t *offset) {
    if (dst == NULL || center == NULL) {
        return ERR_PARAM_DOT_NULLPTR;
    }
    if (offset == NULL) {
        return ERR_PARAM_VECTOR_NULLPTR;
    }

    dst->x = center->x + offset->x;
    dst->y = center->y + offset->y;
    dst->z = center->z + offset->z;

    return ERR_OK;
}

return_code_t vector_scaling(vector_t *vector, const scaling_params_t *scaling_params) {
    if (vector == NULL) {
        return ERR_PARAM_VECTOR_NULLPTR;
    }
    if (scaling_params == NULL) {
        return ERR_PARAM_SCALING_NULLPTR;
    }
    if (fabs(scaling_params->kx) < EPS || fabs(scaling_params->ky) < EPS 
                                       || fabs(scaling_params->kz) < EPS) {
        return ERR_PARAM_SCALING_INVALID;
    }

    vector->x *= scaling_params->kx;
    vector->y *= scaling_params->ky;
    vector->z *= scaling_params->kz;

    return ERR_OK;
}

return_code_t vector_rotate(vector_t *vector, const rotate_params_t *rotate_params) {
    if (vector == NULL) {
        return ERR_PARAM_VECTOR_NULLPTR;
    }
    if (rotate_params == NULL) {
        return ERR_PARAM_ROTATE_NULLPTR;
    }
    
    return_code_t rc = vector_rotate_x(vector, rotate_params->angle_ox);
    if (rc == ERR_OK) {
        rc = vector_rotate_y(vector, rotate_params->angle_oy);
    }
    if (rc == ERR_OK) {
        rc = vector_rotate_z(vector, rotate_params->angle_oz);
    }

    return rc;
}

static double radians(const double angle) {
    return angle * 2 * M_PI / MAX_DEGREES;
}

static return_code_t vector_rotate_x(vector_t *vector, const double angle) {
    if (vector == NULL) {
        return ERR_PARAM_VECTOR_NULLPTR;
    }

    double angle_rads = radians(angle);
    double sin_ang = sin(angle_rads);
    double cos_ang = cos(angle_rads);

    double prev_y = vector->y;
    double prev_z = vector->z;

    vector->y = prev_y * cos_ang - prev_z * sin_ang;
    vector->z = prev_y * sin_ang + prev_z * cos_ang;

    return ERR_OK;
}

static return_code_t vector_rotate_y(vector_t *vector, const double angle) {
    if (vector == NULL) {
        return ERR_PARAM_VECTOR_NULLPTR;
    }

    double angle_rads = radians(angle);
    double sin_ang = sin(angle_rads);
    double cos_ang = cos(angle_rads);

    double prev_x = vector->x;
    double prev_z = vector->z;

    vector->x = prev_x * cos_ang + prev_z * sin_ang;
    vector->z = prev_z * cos_ang - prev_x * sin_ang;

    return ERR_OK;
}

static return_code_t vector_rotate_z(vector_t *vector, const double angle) {
    if (vector == NULL) {
        return ERR_PARAM_VECTOR_NULLPTR;
    }

    double angle_rads = radians(angle);
    double sin_ang = sin(angle_rads);
    double cos_ang = cos(angle_rads);

    double prev_x = vector->x;
    double prev_y = vector->y;

    vector->x = prev_x * cos_ang - prev_y * sin_ang;
    vector->y = prev_x * sin_ang + prev_y * cos_ang;

    return ERR_OK;
}
