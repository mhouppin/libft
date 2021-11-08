#include "ft_barray.h"

int barray_push_back(ByteArray *b, char c)
{
    if (b->size == b->maxSize && barray_auto_expand(b))
        return -1;

    b->data[b->size++] = (uint8_t)c;
    return 0;
}
