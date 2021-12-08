#include "ft_math.h"

double ft_fclamp(double x, double lower, double upper)
{
    return (x < lower) ? lower : (x > upper) ? upper : x;
}
