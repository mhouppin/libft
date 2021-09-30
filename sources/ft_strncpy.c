#include "ft_string.h"

char *ft_strncpy(char *restrict dst, const char *restrict src, size_t size)
{
    size_t i;

    for (i = 0; i < size && src[i]; ++i)
        dst[i] = src[i];

    while (i < size)
        dst[i++] = '\0';

    return dst;
}
