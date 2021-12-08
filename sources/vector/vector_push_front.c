#include "ft_string.h"
#include "ft_vector.h"

int vector_push_front(Vector *vec, const void *item)
{
    if (vec->itemCount == vec->maxItemCount && vector_auto_expand(vec))
        return -1;

    ft_memmove(vec->data + vec->itemSize, vec->data, vec->itemCount * vec->itemSize);
    ft_memcpy(vec->data, item, vec->itemSize);
    ++vec->itemCount;
    return 0;
}
