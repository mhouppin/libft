#include "ft_string.h"

char *ft_stpcpy(char *dst, const char *src)
{
    while (*src)
        *(dst++) = *(src++);
    *dst = '\0';
    return dst;
}
