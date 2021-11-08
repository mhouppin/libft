#include "ft_vector.h"

void *vector_at(const Vector *vec, size_t index)
{
    return vec->data + index * vec->itemSize;
}
