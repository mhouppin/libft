#include <stdint.h>
#include "ft_string.h"

int ft_memcmp(const void *s1, const void *s2, size_t size)
{
    const uint8_t *s1p = s1;
    const uint8_t *s2p = s2;

    while (size)
    {
        int s1b = (int)*s1p;
        int s2b = (int)*s2p;

        if (s1b != s2b)
            return s1b - s2b;
        ++s1p;
        ++s2p;
        --size;
    }
    return 0;
}
