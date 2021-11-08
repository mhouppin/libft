#include <stdlib.h>
#include "ft_string.h"
#include "ft_vector.h"

int vector_shrink_to_fit(Vector *vec)
{
    void *ptr = malloc(vec->itemCount * vec->itemSize);
    if (ptr == NULL)
        return -1;

    ft_memcpy(ptr, vec->data, vec->itemCount * vec->itemSize);
    free(vec->data);
    vec->data = ptr;
    vec->maxItemCount = vec->itemCount;
    return 0;
}
