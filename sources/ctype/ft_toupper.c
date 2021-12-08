#include "ft_ctype.h"

int ft_toupper(int c)
{
    return (c >= 'a' && c <= 'z') ? c + 'A' - 'a' : c;
}
