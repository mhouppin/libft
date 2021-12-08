#include "ft_string.h"

char *ft_strsub(const char *s, size_t start, size_t size)
{
    return ft_strndup(s + start, size);
}
