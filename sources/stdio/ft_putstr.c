#include "ft_stdio.h"

int ft_putstr(const char *s)
{
    return ft_dputstr(s, STDOUT_FILENO);
}
