#include <stdlib.h>
#include "ft_string.h"
#include "ft_vector.h"

int ft_vreserve(Vector *vec, size_t newCapacity)
{
    if (newCapacity <= vec->maxItemCount)
        return 0;

    void *ptr = malloc(vec->itemSize * newCapacity);

    if (ptr == NULL)
        return (-1);

    ft_memcpy(ptr, vec->data, vec->itemSize * vec->itemCount);
    free(vec->data);
    vec->data = ptr;
    vec->maxItemCount = newCapacity;
    return 0;
}
