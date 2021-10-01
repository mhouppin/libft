#include "ft_string.h"

char *ft_strchrnul(const char *s, int c)
{
    while (*s)
    {
        if (*s == c)
            return (char *)s;
        ++s;
    }
    return NULL;
}
