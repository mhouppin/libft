#include "ft_string.h"

void ft_bzero(void *b, size_t size)
{
    ft_memset(b, 0, size);
}
