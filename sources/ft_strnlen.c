#include "ft_string.h"

size_t ft_strnlen(const char *s, size_t maxlen)
{
    size_t i = 0;

    while (s[i] && i < maxlen)
        ++i;
    return i;
}
