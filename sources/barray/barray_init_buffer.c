#include "ft_barray.h"

void barray_init_buffer(ByteArray *b, void *data, size_t size)
{
    b->data = data;
    b->size = size;
    b->maxSize = size;
}
