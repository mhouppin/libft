#include "ft_barray.h"
#include "ft_string.h"

void ft_berase_range(ByteArray *b, size_t start, size_t end)
{
    b->size -= end - start;
    ft_memmove(b->data + start, b->data + end, b->size - start);
}
