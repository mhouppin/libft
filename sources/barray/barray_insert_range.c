#include "ft_barray.h"
#include "ft_string.h"

int barray_insert_range(ByteArray *b, size_t index, const void *data, size_t size)
{
    if (b->size + size > b->maxSize && barray_reserve(b, b->size + size))
        return -1;

    ft_memmove(b->data + index + size, b->data + index, b->size - index);
    ft_memcpy(b->data + index, data, size);
    b->size += size;
    return 0;
}
