#include "ft_math.h"

long double ft_fabsl(long double value)
{
    return (value < 0.0l) ? -value : value;
}
