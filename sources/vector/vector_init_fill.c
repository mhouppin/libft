#include <stdlib.h>
#include "ft_vector.h"

int vector_init_fill(Vector *vec, size_t itemSize, size_t itemCount, void (*itemCtor)(void *))
{
    vec->data = malloc(itemSize * itemCount);
    if (vec->data == NULL)
        return -1;

    vec->itemSize = itemSize;
    vec->itemCount = itemCount;
    vec->maxItemCount = itemCount;
    vec->itemCtor = NULL;
    vec->itemDtor = NULL;
    for (size_t i = 0; i < itemCount; ++i)
        itemCtor(vector_at(vec, i));

    return 0;
}
