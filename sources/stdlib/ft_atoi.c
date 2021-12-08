#include "ft_ctype.h"
#include "ft_stdlib.h"

int ft_atoi(const char *s)
{
    int value, sign;

    while (ft_isspace(*s))
        ++s;

    sign = (*s == '-');
    s += (*s == '-' || *s == '+');
    value = 0;
    while (ft_isdigit(*s))
    {
        value = value * 10 + *s - '0';
        ++s;
    }
    return sign ? -value : value;
}
