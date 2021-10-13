#include "ft_barray.h"
#include "ft_stdio.h"
#include "ft_string.h"

int ft_vsprintf(char *restrict str, const char *restrict fmt, va_list ap)
{
    ByteArray b;

    if (ft_binit_vformat(&b, fmt, ap))
        return -1;

    ft_memcpy(str, b.data, b.size);
    str[b.size] = '\0';

    int retval = b.size;

    ft_bdestroy(&b);
    return retval;
}
