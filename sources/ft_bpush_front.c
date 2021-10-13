#include "ft_barray.h"
#include "ft_string.h"

int ft_bpush_front(ByteArray *b, char c)
{
    if (b->size == b->maxSize && ft_bauto_expand(b))
        return -1;

    ft_memmove(b->data + 1, b->data, b->size++);
    *b->data = (uint8_t)c;
    return 0;
}
