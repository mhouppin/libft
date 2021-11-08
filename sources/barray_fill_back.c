#include "ft_barray.h"
#include "ft_string.h"

int barray_fill_back(ByteArray *b, char c, size_t size)
{
    if (b->size + size > b->maxSize && barray_reserve(b, b->size + size))
        return -1;

    ft_memset(b->data + b->size, c, size);
    b->size += size;
    return 0;
}
