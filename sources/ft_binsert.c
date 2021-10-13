#include "ft_barray.h"
#include "ft_string.h"

int ft_binsert(ByteArray *b, size_t index, char c)
{
    if (b->size == b->maxSize && ft_bauto_expand(b))
        return -1;

    ft_memmove(b->data + index + 1, b->data + index, b->size - index);
    b->data[index] = (uint8_t)c;
    ++b->size;
    return 0;
}
