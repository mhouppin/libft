#include "ft_string.h"
#include "ft_vector.h"

int vector_insert_range(Vector *vec, size_t index, const void *items, size_t itemCount)
{
    if (vec->itemCount + itemCount > vec->maxItemCount && vector_reserve(vec, vec->itemCount + itemCount))
        return -1;

    char *where = vector_at(vec, index);

    ft_memmove(where + itemCount * vec->itemSize, where, (vec->itemCount - index) * vec->itemSize);
    ft_memcpy(where, items, itemCount * vec->itemSize);
    vec->itemCount += vec->itemSize;
    return 0;
}
