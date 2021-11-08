#include <stdlib.h>
#include "ft_barray.h"

void barray_destroy(ByteArray *b)
{
    free(b->data);
    b->data = NULL;
    b->size = 0;
    b->maxSize = 0;
}
