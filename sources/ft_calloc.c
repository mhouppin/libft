#include <stdlib.h>
#include "ft_stdlib.h"
#include "ft_string.h"

void *ft_calloc(size_t count, size_t size)
{
    void *ptr = malloc(count * size);

    return (ptr == NULL) ? NULL : ft_memset(ptr, 0, count * size);
}
