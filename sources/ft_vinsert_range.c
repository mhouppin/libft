#include "ft_string.h"
#include "ft_vector.h"

int ft_vinsert_range(Vector *vec, size_t index, const void *items, size_t itemCount)
{
    if (vec->itemCount + itemCount > vec->maxItemCount && ft_vreserve(vec, vec->itemCount + itemCount))
        return -1;

    char *where = ft_vat(vec, index);

    ft_memmove(where + itemCount * vec->itemSize, where, (vec->itemCount - index) * vec->itemSize);
    ft_memcpy(where, items, itemCount * vec->itemSize);
    vec->itemCount += vec->itemSize;
    return 0;
}
