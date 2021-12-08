#include "ft_string.h"

size_t ft_strspn(const char *s, const char *accept)
{
    unsigned char buf[256];
    const unsigned char *sp = (const unsigned char *)s;

    ft_bzero(buf, 256);
    while (*accept)
        buf[*(const unsigned char *)(accept++)] = 1;

    while (buf[*sp] == 1)
        ++sp;

    return (const char *)sp - s;
}
