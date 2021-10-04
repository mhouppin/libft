#ifndef FT_MATH_H
# define FT_MATH_H

# include <float.h>
# include <math.h>
# include <stdint.h>

# define SQRT_CYCLES(value) (int)(sizeof(int) * 8 - __builtin_clz((unsigned int)(value) + 1))

double ft_sqrt(double value);
float ft_sqrtf(float value);
intmax_t ft_sqrti(intmax_t value);
long double ft_sqrtl(long double value);
uintmax_t ft_sqrtu(uintmax_t value);

#endif
