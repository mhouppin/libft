#include "ft_stdio.h"

int ft_sprintf(char *restrict str, const char *restrict fmt, ...)
{
    va_list ap;
    int retval;

    va_start(ap, fmt);
    retval = ft_vsprintf(str, fmt, ap);
    va_end(ap);
    return retval;
}
