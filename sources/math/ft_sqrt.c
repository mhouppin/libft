#include "ft_math.h"

double ft_sqrt(double value)
{
    if (isnan(value) || (isinf(value) && value > 0.0))
        return value;

    if (value == 0.0)
        return value;

    if (value < 0.0)
        return NAN;

    double result = 1.0;

    if (value < result)
        while (value < result * result)
            result /= 2.0;
    else
        while (value > result * result)
            result *= 2.0;

    for (int i = 0; i < SQRT_CYCLES(DBL_MANT_DIG); ++i)
        result = (result + value / result) / 2.0;

    return result;
}
