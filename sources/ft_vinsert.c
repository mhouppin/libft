#include "ft_string.h"
#include "ft_vector.h"

int ft_vinsert(Vector *vec, size_t index, const void *item)
{
    if (vec->itemCount == vec->maxItemCount && ft_vauto_expand(vec))
        return -1;

    char *where = ft_vat(vec, index);

    ft_memmove(where + vec->itemSize, where, (vec->itemCount - index) * vec->itemSize);
    ft_memcpy(where, item, vec->itemSize);
    ++vec->itemCount;
    return 0;
}
