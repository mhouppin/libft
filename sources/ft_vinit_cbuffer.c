#include <stdlib.h>
#include "ft_string.h"
#include "ft_vector.h"

int ft_vinit_cbuffer(Vector *vec, size_t itemSize, size_t itemCount, const void *initialData)
{
    vec->data = malloc(itemSize * itemCount);
    if (vec->data == NULL)
        return -1;

    vec->itemSize = itemSize;
    vec->itemCount = itemCount;
    vec->maxItemCount = itemCount;
    vec->itemCtor = NULL;
    vec->itemDtor = NULL;
    ft_memcpy(vec->data, initialData, itemSize * itemCount);
    return 0;
}
