#include "ft_stdio.h"

int ft_asprintf(char **str, const char *fmt, ...)
{
    va_list ap;
    int retval;

    va_start(ap, fmt);
    retval = ft_vasprintf(str, fmt, ap);
    va_end(ap);
    return retval;
}
