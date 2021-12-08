#include "ft_stdio.h"

int ft_putendl(const char *str)
{
    return ft_dputendl(str, STDOUT_FILENO);
}
