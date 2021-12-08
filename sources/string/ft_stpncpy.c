#include "ft_string.h"

char *ft_stpncpy(char *dst, const char *src, size_t size)
{
    size_t i;

    for (i = 0; src[i] && i < size; ++i)
        dst[i] = src[i];

    for (size_t j = i; j < size; ++j)
        dst[j] = '\0';

    return dst + i;
}
