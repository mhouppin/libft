#include "ft_string.h"
#include "ft_vector.h"

void ft_verase_range(Vector *vec, size_t start, size_t end)
{
    char *items;

    items = ft_vat(vec, start);
    if (vec->itemDtor)
        for (size_t i = start; i < end; ++i)
            vec->itemDtor(ft_vat(vec, i));

    vec->itemCount -= (end - start);
    ft_memmove(items, items + (end - start) * vec->itemSize, (vec->itemCount - start) * vec->itemSize);
}
