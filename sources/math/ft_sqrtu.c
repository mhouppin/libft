#include "ft_math.h"

uintmax_t ft_sqrtu(uintmax_t value)
{
    uintmax_t root = 0;
    uintmax_t bit = UINTMAX_C(1) << (sizeof(uintmax_t) * 4 - 2);

    while (bit > value)
        bit >>= 2;

    while (bit)
    {
        root >>= 1;
        if (value >= root + bit)
        {
            value -= root + bit;
            root += bit;
        }
        bit >>= 2;
    }

    return root;
}
