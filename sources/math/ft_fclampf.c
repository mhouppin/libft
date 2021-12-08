#include "ft_math.h"

float ft_fclampf(float x, float lower, float upper)
{
    return (x < lower) ? lower : (x > upper) ? upper : x;
}
