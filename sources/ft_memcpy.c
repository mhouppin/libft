#include "ft_string.h"

void *ft_memcpy(void *restrict dst, const void *restrict src, size_t size)
{
    for (size_t i = 0; i < size; ++i)
        ((char *)dst)[i] = ((const char *)src)[i];
    return dst;
}
