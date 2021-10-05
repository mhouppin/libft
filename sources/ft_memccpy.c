#include "ft_string.h"

void *ft_memccpy(void *restrict dst, const void *restrict src, int c, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        ((char *)dst)[i] = ((const char *)src)[i];
        if (((const char *)src)[i] == c)
            return (void *)((char *)dst + i + 1);
    }
    return NULL;
}
