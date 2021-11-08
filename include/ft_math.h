#ifndef FT_MATH_H
# define FT_MATH_H

# include <float.h>
# include <math.h>
# include <stdint.h>

# define SQRT_CYCLES(value) (int)(sizeof(int) * 8 - __builtin_clz((unsigned int)(value) + 1))

double ft_fabs(double value);
float ft_fabsf(float value);
long double ft_fabsl(long double value);
double ft_fclamp(double value, double lower, double upper);
float ft_fclampf(float value, float lower, float upper);
long double ft_fclampl(long double value, long double lower, long double upper);
double ft_fmax(double left, double right);
float ft_fmaxf(float left, float right);
long double ft_fmaxl(long double left, long double right);
double ft_fmin(double left, double right);
float ft_fminf(float left, float right);
long double ft_fminl(long double left, long double right);
intmax_t ft_clampi(intmax_t value, intmax_t lower, intmax_t upper);
uintmax_t ft_clampu(uintmax_t value, uintmax_t lower, uintmax_t upper);
intmax_t ft_maxi(intmax_t left, intmax_t right);
uintmax_t ft_maxu(uintmax_t left, uintmax_t right);
intmax_t ft_mini(intmax_t left, intmax_t right);
uintmax_t ft_minu(uintmax_t left, uintmax_t right);
double ft_sqrt(double value);
float ft_sqrtf(float value);
intmax_t ft_sqrti(intmax_t value);
long double ft_sqrtl(long double value);
uintmax_t ft_sqrtu(uintmax_t value);

#endif
