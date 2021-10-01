#include "ft_math.h"

intmax_t ft_sqrti(intmax_t value)
{
    if (value < 0)
        return -(intmax_t)ft_sqrtu(-value);
    return ft_sqrtu(value);
}
