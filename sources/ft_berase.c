#include "ft_barray.h"
#include "ft_string.h"

void ft_berase(ByteArray *b, size_t index)
{
    --b->size;
    ft_memmove(b->data + index, b->data + index + 1, b->size - index);
}
