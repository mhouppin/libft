#include "ft_stdio.h"

int ft_vprintf(const char *restrict fmt, va_list ap)
{
    return ft_vdprintf(STDOUT_FILENO, fmt, ap);
}
