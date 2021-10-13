#include "ft_barray.h"

int ft_bpush_back(ByteArray *b, char c)
{
    if (b->size == b->maxSize && ft_bauto_expand(b))
        return -1;

    b->data[b->size++] = (uint8_t)c;
    return 0;
}
