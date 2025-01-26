#include "size.h"
#include "errors.h"

size_t size_init(void) {
    return 0;
}

return_code_t size_read(size_t *cnt, FILE *fin) {
    if (cnt == NULL) {
        return ERR_PARAM_SIZE_NULLPTR;
    }
    if (fin == NULL) {
        return ERR_PARAM_FILE_NULLPTR;
    }

    return_code_t rc = ERR_OK;
    size_t tmp;

    if (fscanf(fin, "%lu", &tmp) != 1) {
        rc = ERR_FILE_READ;
    }
    else {
        *cnt = tmp;
    }

    return rc;
}

return_code_t size_write(const size_t cnt, FILE *fout) {
    if (fout == NULL) {
        return ERR_PARAM_FILE_NULLPTR;
    }

    fprintf(fout, "%lu\n", cnt);
    
    return ERR_OK;
}
