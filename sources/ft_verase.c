#include "ft_string.h"
#include "ft_vector.h"

void ft_verase(Vector *vec, size_t index)
{
    char *item = ft_vat(vec, index);

    if (vec->itemDtor)
        vec->itemDtor(item);
    --vec->itemCount;
    ft_memmove(item, item + vec->itemSize, (vec->itemCount - index) * vec->itemSize);
}
