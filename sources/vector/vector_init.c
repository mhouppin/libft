#include "ft_vector.h"

void vector_init(Vector *vec, size_t itemSize)
{
    vec->data = NULL;
    vec->itemSize = itemSize;
    vec->itemCount = 0;
    vec->maxItemCount = 0;
    vec->itemCtor = NULL;
    vec->itemDtor = NULL;
}
