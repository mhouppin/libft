#include "ft_math.h"

intmax_t ft_clampi(intmax_t value, intmax_t lower, intmax_t upper)
{
    return (value < lower) ? lower : (value > upper) ? upper : value;
}
