#include <stdint.h>
#include "ft_string.h"

int ft_strcmp(const char *s1, const char *s2)
{
    while (*s1 && *s2)
    {
        if (*s1 != *s2)
            break ;

        ++s1;
        ++s2;
    }
    return (int)*(const uint8_t *)s1 - (int)*(const uint8_t *)s2;
}
