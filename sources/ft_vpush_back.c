#include "ft_string.h"
#include "ft_vector.h"

int ft_vpush_back(Vector *vec, const void *item)
{
    if (vec->itemCount == vec->maxItemCount && ft_vauto_expand(vec))
        return -1;

    ft_memcpy(ft_vat(vec, vec->itemCount), item, vec->itemSize);
    ++vec->itemCount;
    return 0;
}
