#include <stdlib.h>
#include "ft_barray.h"
#include "ft_string.h"

int ft_bshrink_to_fit(ByteArray *b)
{
    void *ptr = malloc(b->size);
    if (ptr == NULL)
        return -1;

    ft_memcpy(ptr, b->data, b->size);
    free(b->data);
    b->data = ptr;
    b->maxSize = b->size;
    return 0;
}
