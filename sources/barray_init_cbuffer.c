#include <stdlib.h>
#include "ft_barray.h"
#include "ft_string.h"

int barray_init_cbuffer(ByteArray *b, const void *data, size_t size)
{
    b->data = malloc(size);
    if (b->data == NULL)
        return -1;

    ft_memcpy(b->data, data, size);
    b->size = size;
    b->maxSize = size;
    return 0;
}
