#include "ft_barray.h"
#include "ft_math.h"
#include "ft_stdio.h"
#include "ft_string.h"

int ft_vsnprintf(char *restrict str, size_t size, const char *restrict fmt, va_list ap)
{
    ByteArray b;

    if (ft_binit_vformat(&b, fmt, ap))
        return -1;

    if (size != 0)
    {
        size_t copySize = ft_maxu(size - 1, b.size);

        ft_memcpy(str, b.data, copySize);
        str[copySize] = '\0';
    }

    int retval = b.size;

    ft_bdestroy(&b);
    return retval;
}
