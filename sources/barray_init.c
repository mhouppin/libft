#include "ft_barray.h"

void barray_init(ByteArray *b)
{
    b->data = NULL;
    b->size = 0;
    b->maxSize = 0;
}
