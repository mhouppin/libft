#include "ft_barray.h"
#include "ft_string.h"

int barray_fill(ByteArray *b, size_t index, char c, size_t size)
{
    if (b->size + size > b->maxSize && barray_reserve(b, b->size + size))
        return -1;

    ft_memmove(b->data + index + size, b->data + index, b->size - index);
    ft_memset(b->data + index, c, size);
    b->size += size;
    return 0;
}
