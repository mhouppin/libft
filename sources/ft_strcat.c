#include "ft_string.h"

char *ft_strcat(char *restrict dst, const char *restrict src)
{
    char *dstp = dst + ft_strlen(dst);

    while (*src)
        *dstp++ = *src++;
    *dstp = *src;
    return dst;
}
