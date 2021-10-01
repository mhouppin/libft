#include "ft_string.h"

char *ft_strtok_r(char *s, const char *delim, char **oldptr)
{
    if (!s)
        s = *oldptr;
    if (!*s)
    {
        *oldptr = s;
        return NULL;
    }

    s += ft_strspn(s, delim);
    if (!*s)
    {
        *oldptr = s;
        return NULL;
    }

    char *end = s + ft_strcspn(s, delim);
    if (!*end)
    {
        *oldptr = end;
        return s;
    }

    *end = '\0';
    *oldptr = end + 1;
    return s;
}
