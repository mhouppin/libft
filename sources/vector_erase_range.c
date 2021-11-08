#include "ft_string.h"
#include "ft_vector.h"

void vector_erase_range(Vector *vec, size_t start, size_t end)
{
    char *items;

    items = vector_at(vec, start);
    if (vec->itemDtor)
        for (size_t i = start; i < end; ++i)
            vec->itemDtor(vector_at(vec, i));

    vec->itemCount -= (end - start);
    ft_memmove(items, items + (end - start) * vec->itemSize, (vec->itemCount - start) * vec->itemSize);
}
