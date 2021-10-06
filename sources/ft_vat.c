#include "ft_vector.h"

void *ft_vat(const Vector *vec, size_t index)
{
    return vec->data + index * vec->itemSize;
}
