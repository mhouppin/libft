#include "ft_barray.h"

int ft_binit_format(ByteArray *b, const char *fmt, ...)
{
    va_list ap;
    int retval;

    va_start(ap, fmt);
    retval = ft_binit_vformat(b, fmt, ap);
    va_end(ap);
    return retval;
}
