#include "ft_math.h"

uintmax_t ft_clampu(uintmax_t value, uintmax_t lower, uintmax_t upper)
{
    return (value < lower) ? lower : (value > upper) ? upper : value;
}
