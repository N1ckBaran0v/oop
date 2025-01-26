#include <stdlib.h>
#include <math.h>

#include "errors.h"
#include "segment.h"
#include "size.h"

static segment_t *segments_alloc(const size_t nmemb);

static return_code_t segment_tmp_read(segment_t *seg_tmp, FILE *fin);

static return_code_t segment_arr_tmp_read(segment_arr_t *seg_arr_tmp, FILE *fin);

static return_code_t segments_tmp_read(segment_t *segs_tmp, const size_t size, FILE *fin);

static return_code_t segment_check(const segment_t *segment, const size_t dots_cnt);

static return_code_t segments_check(const segment_t *segments, const size_t size, const size_t dots_cnt);

static return_code_t segment_write(const segment_t *segment, FILE *fout);

static return_code_t segments_write(const segment_t *segments, const size_t size, FILE *fout);

static screen_place_t *screen_places_alloc(const size_t nmemb);

static return_code_t screen_places_find(screen_place_t *screen_places, const dot_t *dots, const size_t size,
                                                                       const scene_t *scene);

static return_code_t screen_place_find(screen_place_t *dot_place, const dot_t *dot, 
                                       const screen_place_t *center, const double screen_scale);

static void dots_screen_places_destroy(screen_place_t *screen_places);

static return_code_t segments_draw(const segment_t *segments, const size_t seg_cnt, 
                                   const screen_place_t *dots, const scene_t *scene);

static return_code_t segment_draw(const segment_t *segment, const screen_place_t *dots, const scene_t *scene);

static return_code_t segment_draw_with_dots(QPainter *pen, const screen_place_t *first, 
                                                           const screen_place_t *second);

static int screen_place(const double coordinate, const double screen_scale, const int center_pos);

segment_arr_t segment_arr_init(void) {
    segment_arr_t segment_arr;

    segment_arr.size = 0;
    segment_arr.arr = NULL;

    return segment_arr;
}

return_code_t segment_arr_read(segment_arr_t *segment_arr, FILE *fin) {
    if (segment_arr == NULL) {
        return ERR_PARAM_SEGMENT_ARR_NULLPTR;
    }
    if (fin == NULL) {
        return ERR_PARAM_FILE_NULLPTR;
    }

    return_code_t rc = ERR_OK;
    segment_arr_t tmp_seg_arr = segment_arr_init();

    rc = segment_arr_tmp_read(&tmp_seg_arr, fin);
    if (rc != ERR_OK) {
        segment_arr_destroy(&tmp_seg_arr);
    }
    else {
        segment_arr_destroy(segment_arr);
        *segment_arr = tmp_seg_arr;
    }

    return rc;
}

return_code_t segment_arr_write(const segment_arr_t *segment_arr, FILE *fout) {
    if (segment_arr == NULL) {
        return ERR_PARAM_SEGMENT_ARR_NULLPTR;
    }
    if (fout == NULL) {
        return ERR_PARAM_FILE_NULLPTR;
    }

    return_code_t rc = size_write(segment_arr->size, fout);
    if (rc == ERR_OK) {
        rc = segments_write(segment_arr->arr, segment_arr->size, fout);
    }

    return rc;
}

return_code_t segment_arr_draw(const segment_arr_t *segment_arr, const dot_arr_t *dot_arr, const scene_t *scene) {
    if (segment_arr == NULL) {
        return ERR_PARAM_SEGMENT_ARR_NULLPTR;
    }
    if (dot_arr == NULL) {
        return ERR_PARAM_DOT_ARR_NULLPTR;
    }
    if (scene == NULL) {
        return ERR_PARAM_SCENE_NULLPTR;
    }

    return_code_t rc = ERR_OK;
    screen_place_t *screen_places = NULL;

    rc = segment_arr_check(segment_arr, dot_arr->size);
    if (rc == ERR_OK) {
        screen_places = screen_places_alloc(dot_arr->size);
        if (screen_places == NULL) {
            rc = ERR_MEM_ALLOC;
        }
        else {
            rc = screen_places_find(screen_places, dot_arr->arr, dot_arr->size, scene);
            if (rc == ERR_OK) {
                rc = segments_draw(segment_arr->arr, segment_arr->size, screen_places, scene);
            }
            dots_screen_places_destroy(screen_places);
        }
    }
    

    return rc;
}

return_code_t segment_arr_check(const segment_arr_t *segment_arr, const size_t dots_cnt) {
    if (segment_arr == NULL) {
        return ERR_PARAM_SEGMENT_ARR_NULLPTR;
    }

    return segments_check(segment_arr->arr, segment_arr->size, dots_cnt);
}

void segment_arr_destroy(segment_arr_t *segment_arr) {
    if (segment_arr == NULL) {
        return;
    }

    segment_arr->size = 0;
    free(segment_arr->arr);
    segment_arr->arr = NULL;
}

static segment_t *segments_alloc(const size_t nmemb) {
    if (nmemb == 0)
        return NULL;

    return (segment_t*)calloc(nmemb, sizeof(segment_t));
}

static return_code_t segment_tmp_read(segment_t *seg_tmp, FILE *fin) {
    if (seg_tmp == NULL) {
        return ERR_PARAM_SEGMENT_NULLPTR;
    }
    if (fin == NULL) {
        return ERR_PARAM_FILE_NULLPTR;
    }

    return_code_t rc = ERR_OK;

    if (fscanf(fin, "%lu %lu", &(seg_tmp->first), &(seg_tmp->second)) != 2) {
        rc = ERR_FILE_READ;
    }

    return rc;
}

static return_code_t segment_arr_tmp_read(segment_arr_t *seg_arr_tmp, FILE *fin) {
    if (seg_arr_tmp == NULL) {
        return ERR_PARAM_SEGMENT_ARR_NULLPTR;
    }
    if (fin == NULL) {
        return ERR_PARAM_FILE_NULLPTR;
    }

    return_code_t rc = size_read(&(seg_arr_tmp->size), fin);
    if (rc == ERR_OK) {
        seg_arr_tmp->arr = segments_alloc(seg_arr_tmp->size);
        if (seg_arr_tmp->arr == NULL) {
            rc = ERR_MEM_ALLOC;
        }
    }
    if (rc == ERR_OK) {
        rc = segments_tmp_read(seg_arr_tmp->arr, seg_arr_tmp->size, fin);
    }

    return rc;
}

static return_code_t segments_tmp_read(segment_t *segs_tmp, const size_t size, FILE *fin) {
    if (segs_tmp == NULL) {
        return ERR_PARAM_SEGMENT_NULLPTR;
    }
    if (fin == NULL) {
        return ERR_PARAM_FILE_NULLPTR;
    }

    return_code_t rc = ERR_OK;

    for (size_t i = 0; rc == ERR_OK && i < size; ++i) {
        rc = segment_tmp_read(segs_tmp + i, fin);
    }

    return rc;
}

static return_code_t segment_check(const segment_t *segment, const size_t dots_cnt) {
    if (segment == NULL) {
        return ERR_PARAM_SEGMENT_NULLPTR;
    }

    return_code_t rc = ERR_OK;

    if (segment->first >= dots_cnt || segment->second >= dots_cnt) {
        rc = ERR_SEGMENT_DOT_INDEX_INVALID;
    }

    return rc;
}

static return_code_t segments_check(const segment_t *segments, const size_t size, const size_t dots_cnt) {
    if (segments == NULL) {
        return ERR_PARAM_SEGMENT_NULLPTR;
    }

    return_code_t rc = ERR_OK;

    for (size_t i = 0; rc == ERR_OK && i < size; ++i) {
        rc = segment_check(segments + i, dots_cnt);
    }

    return rc;
}

static return_code_t segment_write(const segment_t *segment, FILE *fout) {
    if (segment == NULL) {
        return ERR_PARAM_SEGMENT_NULLPTR;
    }
    if (fout == NULL) {
        return ERR_PARAM_FILE_NULLPTR;
    }

    return_code_t rc = ERR_OK;

    fprintf(fout, "%lu %lu\n", segment->first, segment->second);

    return ERR_OK;
}

static return_code_t segments_write(const segment_t *segments, const size_t size, FILE *fout) {
    if (segments == NULL) {
        return ERR_PARAM_SEGMENT_NULLPTR;
    }
    if (fout == NULL) {
        return ERR_PARAM_FILE_NULLPTR;
    }

    return_code_t rc = ERR_OK;

    for (size_t i = 0; rc == ERR_OK && i < size; ++i) {
        rc = segment_write(segments + i, fout);
    }

    return rc;
}

static screen_place_t *screen_places_alloc(const size_t nmemb) {
    if (nmemb == 0)
        return NULL;

    return (screen_place_t*)calloc(nmemb, sizeof(screen_place_t));
}

static return_code_t screen_places_find(screen_place_t *screen_places, const dot_t *dots, const size_t size,
                                                                       const scene_t *scene) {
    if (screen_places == NULL) {
        return ERR_PARAM_SCREEN_PLACE_NULLPTR;
    }
    if (dots == NULL) {
        return ERR_PARAM_DOT_NULLPTR;
    }
    if (scene == NULL) {
        return ERR_PARAM_SCENE_NULLPTR;
    }

    return_code_t rc;

    for (size_t i = 0; rc == ERR_OK && i < size; ++i) {
        rc = screen_place_find(screen_places + i, dots + i, 
                               &(scene->screen_center), scene->screen_scale);
    }

    return rc;   
}

static return_code_t screen_place_find(screen_place_t *dot_place, const dot_t *dot, 
                                       const screen_place_t *center, const double screen_scale) {
    if (dot_place == NULL || center == NULL) {
        return ERR_PARAM_SCREEN_PLACE_NULLPTR;
    }
    if (dot == NULL) {
        return ERR_PARAM_DOT_NULLPTR;
    }

    dot_place->x = screen_place(dot->x, screen_scale, center->x);
    dot_place->y = screen_place(dot->y, -screen_scale, center->y);

    return ERR_OK;
}

static void dots_screen_places_destroy(screen_place_t *screen_places) {
    free(screen_places);
}

static return_code_t segments_draw(const segment_t *segments, const size_t seg_cnt, 
                                   const screen_place_t *dots, const scene_t *scene) {
    if (segments == NULL) {
        return ERR_PARAM_SEGMENT_NULLPTR;
    }
    if (dots == NULL) {
        return ERR_PARAM_SCREEN_PLACE_NULLPTR;
    }
    if (scene == NULL) {
        return ERR_PARAM_SCENE_NULLPTR;
    }

    return_code_t rc;

    for (size_t i = 0; rc == ERR_OK && i < seg_cnt; ++i) {
        rc = segment_draw(segments + i, dots, scene);
    }

    return rc;                            
}

static return_code_t segment_draw(const segment_t *segment, const screen_place_t *dots, const scene_t *scene) {
    if (segment == NULL) {
        return ERR_PARAM_SEGMENT_NULLPTR;
    }
    if (dots == NULL) {
        return ERR_PARAM_SCREEN_PLACE_NULLPTR;
    }
    if (scene == NULL) {
        return ERR_PARAM_SCENE_NULLPTR;
    }

    return segment_draw_with_dots(scene->pen, dots + segment->first, dots + segment->second);
}

static return_code_t segment_draw_with_dots(QPainter *pen, const screen_place_t *first, 
                                                           const screen_place_t *second) {
    if (first == NULL || second == NULL) {
        return ERR_PARAM_SCREEN_PLACE_NULLPTR;
    }
    if (pen == NULL) {
        return ERR_PARAM_PEN_NULLPTR;
    }

    pen->drawLine(first->x, first->y, second->x, second->y);

    return ERR_OK;
}

static int screen_place(const double coordinate, const double screen_scale, const int center_pos) {
    return (int)round(coordinate * screen_scale) + center_pos;
}
