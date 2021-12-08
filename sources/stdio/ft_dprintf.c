#include "ft_stdio.h"

int ft_dprintf(int fd, const char *restrict fmt, ...)
{
    va_list ap;
    int retval;

    va_start(ap, fmt);
    retval = ft_vdprintf(fd, fmt, ap);
    va_end(ap);
    return retval;
}
