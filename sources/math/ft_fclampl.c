#include "ft_math.h"

long double ft_fclampl(long double x, long double lower, long double upper)
{
    return (x < lower) ? lower : (x > upper) ? upper : x;
}
