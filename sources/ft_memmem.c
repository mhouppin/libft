#include <stdint.h>
#include "ft_string.h"

void *ft_memmem(const void *big, size_t biglen, const void *little, size_t littlelen)
{
    void *ptr;
    char c;

    if (littlelen == 0)
        return (void *)big;
    c = *(const char *)little;

    while (biglen >= littlelen)
    {
        ptr = ft_memchr(big, c, biglen);
        if (ptr == NULL)
            break ;

        biglen -= (uintptr_t)ptr - (uintptr_t)big;
        if (biglen < littlelen)
            break ;

        if (!ft_memcmp(ptr, little, littlelen))
            return ptr;

        big = (void *)((char *)ptr + 1);
        --biglen;
    }
    return NULL;
}
