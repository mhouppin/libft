#include "ft_stdlib.h"
#include "ft_vector.h"

void *vector_search(const Vector *vec, const void *key, int (*itemComp)(const void *, const void *))
{
    return ft_bsearch(key, vec->data, vec->itemCount, vec->itemSize, itemComp);
}
