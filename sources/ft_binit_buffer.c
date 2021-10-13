#include "ft_barray.h"

void ft_binit_buffer(ByteArray *b, void *data, size_t size)
{
    b->data = data;
    b->size = size;
    b->maxSize = size;
}
