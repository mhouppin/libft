#include "ft_stdio.h"
#include "ft_string.h"

int ft_dputstr(const char *s, int fd)
{
    return write(fd, s, ft_strlen(s));
}
