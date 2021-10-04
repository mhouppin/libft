#include "ft_stdlib.h"

const char *ft_citoa(int value)
{
    static char buffer[13] = {};
    unsigned int uvalue = ft_abs(value);
    int i = 11;

    while (1)
    {
        buffer[i] = uvalue % 10 + '0';
        uvalue /= 10;
        if (uvalue == 0)
            break ;
        --i;
    }
    if (value < 0)
        buffer[--i] = '-';
    return &buffer[i];
}
