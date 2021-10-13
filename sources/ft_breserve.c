#include <stdlib.h>
#include "ft_barray.h"
#include "ft_string.h"

int ft_breserve(ByteArray *b, size_t newSize)
{
    if (newSize <= b->maxSize)
        return 0;

    void *ptr = malloc(newSize);

    if (ptr == NULL)
        return (-1);

    ft_memcpy(ptr, b->data, b->size);
    free(b->data);
    b->data = ptr;
    b->maxSize = newSize;
    return 0;
}
