#include "ft_stdio.h"
#include "ft_stdlib.h"

int ft_dputnbr(int value, int fd)
{
    return ft_dputstr(ft_citoa(value), fd);
}
