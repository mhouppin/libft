#include "ft_string.h"

size_t ft_strlcpy(char *restrict dst, const char *restrict src, size_t size)
{
    size_t srclen = ft_strlen(src);

    if (srclen < size)
        ft_memcpy(dst, src, srclen + 1);
    else
    {
        ft_memcpy(dst, src, size - 1);
        dst[size - 1] = '\0';
    }
    return srclen;
}
