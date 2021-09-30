#include "ft_ctype.h"

int ft_tolower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
