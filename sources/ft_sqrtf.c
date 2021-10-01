#include "ft_math.h"

float ft_sqrtf(float value)
{
    if (isnan(value) || (isinf(value) && value > 0.0f))
        return value;

    if (value == 0.0f)
        return value;

    if (value < 0.0f)
        return NAN;

    float result = 1.0f;

    if (value < result)
        while (value < result * result)
            result /= 2.0f;
    else
        while (value > result * result)
            result *= 2.0f;

    for (int i = 0; i < SQRT_CYCLES(FLT_MANT_DIG); ++i)
        result = (result + value / result) / 2.0f;

    return result;
}
