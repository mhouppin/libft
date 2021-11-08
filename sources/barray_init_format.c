#include "ft_barray.h"

int barray_init_format(ByteArray *b, const char *fmt, ...)
{
    va_list ap;
    int retval;

    va_start(ap, fmt);
    retval = barray_init_vformat(b, fmt, ap);
    va_end(ap);
    return retval;
}
