#include "ft_string.h"

size_t ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
    size_t dstlen = ft_strnlen(dst, size);
    size_t srclen = ft_strlen(src);

    if (dstlen != size)
    {
        if (srclen >= size - dstlen)
        {
            ft_memcpy(dst + dstlen, src, size - dstlen - 1);
            dst[size - 1] = '\0';
        }
        else
            ft_memcpy(dst + dstlen, src, srclen + 1);
    }
    return dstlen + srclen;
}
