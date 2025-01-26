#ifndef __SEGMENT_H__
#define __SEGMENT_H__

#include <QPainter>

#include "errors.h"
#include "size.h"
#include "dot.h"

struct segment_t {
    size_t first, second;
};

struct segment_arr_t {
    size_t size;
    segment_t *arr;
};

struct screen_place_t {
    int x;
    int y;
};

struct scene_t {
    QPainter *pen;
    screen_place_t screen_center;
    double screen_scale;
};

segment_arr_t segment_arr_init(void);

return_code_t segment_arr_read(segment_arr_t *segment_arr, FILE *fin);

return_code_t segment_arr_write(const segment_arr_t *segment_arr, FILE *fout);

return_code_t segment_arr_draw(const segment_arr_t *segment_arr, const dot_arr_t *dot_arr, const scene_t *scene);

return_code_t segment_arr_check(const segment_arr_t *segment_arr, const size_t dots_cnt);

void segment_arr_destroy(segment_arr_t *segment_arr);

#endif //__SEGMENT_H__