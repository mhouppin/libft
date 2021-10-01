#include "ft_string.h"

size_t ft_strcspn(const char *s, const char *reject)
{
    unsigned char buf[256];
    const unsigned char *sp = (const unsigned char *)s;

    ft_bzero(buf, 256);
    while (*reject)
        buf[*(const unsigned char *)(reject++)] = 1;

    buf[0] = 1;
    while (!buf[*sp])
        sp++;

    return (const char *)sp - s;
}
