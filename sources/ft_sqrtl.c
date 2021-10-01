#include "ft_math.h"

long double ft_sqrtl(long double value)
{
    if (isnan(value) || (isinf(value) && value > 0.0l))
        return value;

    if (value == 0.0l)
        return value;

    if (value < 0.0l)
        return NAN;

    long double result = 1.0l;

    if (value < result)
        while (value < result * result)
            result /= 2.0l;
    else
        while (value > result * result)
            result *= 2.0l;

    for (int i = 0; i < SQRT_CYCLES(LDBL_MANT_DIG); ++i)
        result = (result + value / result) / 2.0l;

    return result;
}
