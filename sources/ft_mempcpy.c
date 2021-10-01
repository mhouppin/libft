#include "ft_string.h"

void *ft_mempcpy(void *restrict dst, const void *restrict src, size_t size)
{
    char *dstp = dst;
    const char *srcp = src;

    while (size--)
        *(dstp++) = *(srcp++);
    return dstp;
}
