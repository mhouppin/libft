#include "ft_vector.h"

void vector_init_buffer(Vector *vec, size_t itemSize, size_t itemCount, void *initialData)
{
    vec->data = initialData;
    vec->itemSize = itemSize;
    vec->itemCount = itemCount;
    vec->maxItemCount = itemCount;
    vec->itemCtor = NULL;
    vec->itemDtor = NULL;
}
