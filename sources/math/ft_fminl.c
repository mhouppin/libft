#include "ft_math.h"

long double ft_fminl(long double left, long double right)
{
    return (left < right) ? left : right;
}
