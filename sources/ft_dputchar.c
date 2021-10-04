#include "ft_stdio.h"

int ft_dputchar(char c, int fd)
{
    return write(fd, &c, 1);
}
