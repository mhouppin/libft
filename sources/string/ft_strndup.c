#include <stdlib.h>
#include "ft_string.h"

char *ft_strndup(const char *s, size_t size)
{
    size_t realSize = ft_strnlen(s, size);
    char *ptr = malloc(realSize + 1);

    if (!ptr)
        return NULL;
    ptr[realSize] = '\0';
    return ft_memcpy(ptr, s, realSize);
}
