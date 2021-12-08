#include "ft_stdlib.h"
#include "ft_string.h"

char *ft_itoa(int value)
{
    return ft_strdup(ft_citoa(value));
}
