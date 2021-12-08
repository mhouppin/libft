#include "ft_stdio.h"

int ft_snprintf(char *restrict str, size_t size, const char *restrict fmt, ...)
{
    va_list ap;
    int retval;

    va_start(ap, fmt);
    retval = ft_vsnprintf(str, size, fmt, ap);
    va_end(ap);
    return retval;
}
