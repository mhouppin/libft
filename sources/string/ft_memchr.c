#include "ft_string.h"

void *ft_memchr(const void *b, int c, size_t size)
{
    for (size_t i = 0; i < size; ++i)
        if (((const char *)b)[i] == c)
            return (void *)((const char *)b + i);

    return NULL;
}
