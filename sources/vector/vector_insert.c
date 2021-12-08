#include "ft_string.h"
#include "ft_vector.h"

int vector_insert(Vector *vec, size_t index, const void *item)
{
    if (vec->itemCount == vec->maxItemCount && vector_auto_expand(vec))
        return -1;

    char *where = vector_at(vec, index);

    ft_memmove(where + vec->itemSize, where, (vec->itemCount - index) * vec->itemSize);
    ft_memcpy(where, item, vec->itemSize);
    ++vec->itemCount;
    return 0;
}
