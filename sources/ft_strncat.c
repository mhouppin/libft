#include "ft_string.h"

char *ft_strncat(char *restrict dst, const char *restrict src, size_t size)
{
    char *dstp = dst + ft_strlen(dst);

    while (*src && size)
    {
        *dstp++ = *src++;
        --size;
    }
    *dstp = '\0';
    return dst;
}
