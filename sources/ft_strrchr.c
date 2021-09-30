#include "ft_string.h"

char *ft_strrchr(const char *s, int c)
{
    if (c == '\0')
        return (char *)s + ft_strlen(s);

    char *last = NULL;

    while (*s)
    {
        if (*s == c)
            last = (char *)s;
        ++s;
    }
    return last;
}
