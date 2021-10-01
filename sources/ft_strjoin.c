#include <stdlib.h>
#include "ft_string.h"

char *ft_strjoin(const char *s1, const char *s2)
{
    size_t s1len = ft_strlen(s1);
    size_t s2len = ft_strlen(s2);
    char *s = malloc(s1len + s2len + 1);

    if (!s)
        return NULL;
    ft_memcpy(s + s1len, s2, s2len + 1);
    return ft_memcpy(s, s1, s1len);
}
