#include <stdlib.h>
#include "ft_string.h"

char *ft_strdup(const char *s)
{
    size_t size = ft_strlen(s) + 1;
    void *ptr = malloc(size);

    return (ptr == NULL) ? NULL : ft_memcpy(ptr, s, size);
}
