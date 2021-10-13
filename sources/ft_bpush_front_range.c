#include "ft_barray.h"
#include "ft_string.h"

int ft_bpush_front_range(ByteArray *b, const void *data, size_t size)
{
    if (b->size + size > b->maxSize && ft_breserve(b, b->size + size))
        return -1;

    ft_memmove(b->data + size, b->data, b->size);
    ft_memcpy(b->data, data, size);
    b->size += size;
    return 0;
}
