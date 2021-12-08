#include "ft_stdlib.h"
#include "ft_vector.h"

void vector_sort(Vector *vec, int (*itemComp)(const void *, const void *))
{
    ft_quicksort(vec->data, vec->itemCount, vec->itemSize, itemComp);
}
