#ifndef __ERRORS_H__
#define __ERRORS_H__

enum return_code_t {ERR_OK, ERR_PARAM_DOT_NULLPTR, ERR_PARAM_FILE_NULLPTR, 
                    ERR_PARAM_VECTOR_NULLPTR, ERR_PARAM_CENTER_NULLPTR,
                    ERR_PARAM_SCALING_NULLPTR, ERR_PARAM_ROTATE_NULLPTR,
                    ERR_PARAM_SCALING_INVALID, ERR_PARAM_SEGMENT_NULLPTR,
                    ERR_PARAM_MODEL_NULLPTR, ERR_PARAM_FILENAME_NULLPTR,
                    ERR_PARAM_SIZE_NULLPTR, ERR_PARAM_SCENE_NULLPTR,
                    ERR_PARAM_PEN_NULLPTR, ERR_PARAM_PARAMS_NULLPTR,
                    ERR_PARAM_DOT_ARR_NULLPTR, ERR_PARAM_SEGMENT_ARR_NULLPTR,
                    ERR_PARAM_SCREEN_PLACE_NULLPTR,
                    ERR_ACTION_INVALID, ERR_MEM_ALLOC, ERR_FILE_OPEN, 
                    ERR_SEGMENT_DOT_INDEX_INVALID, ERR_PARAM_STR_NULLPTR, 
                    ERR_FILE_READ, ERR_FILE_WRITE};

#endif //__ERRORS_H__