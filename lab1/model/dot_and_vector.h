#ifndef __DOT_AND_VECTOR_H__
#define __DOT_AND_VECTOR_H__

#define EPS 5e-7

struct dot_t {
    double x, y, z;
};

struct vector_t {
    double x, y, z;
};

struct scaling_params_t {
    double kx, ky, kz;
};

struct rotate_params_t {
    double angle_ox, angle_oy, angle_oz;
};

#endif //__DOT_AND_VECTOR_H__