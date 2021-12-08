#include "ft_barray.h"
#include "ft_string.h"

int barray_insert(ByteArray *b, size_t index, char c)
{
    if (b->size == b->maxSize && barray_auto_expand(b))
        return -1;

    ft_memmove(b->data + index + 1, b->data + index, b->size - index);
    b->data[index] = (uint8_t)c;
    ++b->size;
    return 0;
}
