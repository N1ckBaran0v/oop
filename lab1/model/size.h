#ifndef __SIZE_H__
#define __SIZE_H__

#include <stdio.h>
#include <stddef.h>
#include "errors.h"

size_t size_init(void);

return_code_t size_read(size_t *cnt, FILE *fin);

return_code_t size_write(const size_t cnt, FILE *fout);

#endif // __SIZE_H__