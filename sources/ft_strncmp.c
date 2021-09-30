#include <stdint.h>
#include "ft_string.h"

int ft_strncmp(const char *s1, const char *s2, size_t size)
{
    while (size && *s1)
    {
        if (*s1 != *s2)
            break ;
        ++s1;
        ++s2;
        --size;
    }
    return !size ? 0 : (int)*(const uint8_t *)s1 - (int)*(const uint8_t *)s2;
}
