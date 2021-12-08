#include "ft_stdio.h"

int ft_printf(const char *restrict fmt, ...)
{
    va_list ap;
    int retval;

    va_start(ap, fmt);
    retval = ft_vprintf(fmt, ap);
    va_end(ap);
    return retval;
}
