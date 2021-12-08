#include "ft_stdlib.h"
#include "ft_vector.h"

size_t vector_index(const Vector *vec, const void *key, int (*itemComp)(const void *, const void *))
{
    return ft_bindex(key, vec->data, vec->itemCount, vec->itemSize, itemComp);
}
