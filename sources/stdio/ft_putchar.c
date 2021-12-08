#include "ft_stdio.h"

int ft_putchar(char c)
{
    return ft_dputchar(c, STDOUT_FILENO);
}
