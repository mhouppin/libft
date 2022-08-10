#include "ft_math.h"

uintmax_t ft_powu(uintmax_t factor, uintmax_t exponent)
{
    uintmax_t result = 1;

    while (exponent)
    {
        if (exponent & 1)
            result *= factor;

        exponent >>= 1;
        factor *= factor;
    }

    return result;
}
