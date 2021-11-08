#include "ft_string.h"
#include "ft_vector.h"

int vector_push_back(Vector *vec, const void *item)
{
    if (vec->itemCount == vec->maxItemCount && vector_auto_expand(vec))
        return -1;

    ft_memcpy(vector_at(vec, vec->itemCount), item, vec->itemSize);
    ++vec->itemCount;
    return 0;
}
