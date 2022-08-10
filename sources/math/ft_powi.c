#include "ft_math.h"

intmax_t ft_powi(intmax_t factor, uintmax_t exponent)
{
    intmax_t result = 1;

    while (exponent)
    {
        if (exponent & 1)
            result *= factor;

        exponent >>= 1;
        factor *= factor;
    }

    return result;
}
