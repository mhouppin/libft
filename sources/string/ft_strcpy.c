#include "ft_string.h"

char *ft_strcpy(char *restrict dst, const char *restrict src)
{
    char *dstp = dst;

    while (*src)
        *(dst++) = *(src++);
    *dst = *src;
    return dstp;
}
