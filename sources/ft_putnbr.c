#include "ft_stdio.h"

int ft_putnbr(int value)
{
    return ft_dputnbr(value, STDOUT_FILENO);
}
