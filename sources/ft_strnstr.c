#include "ft_string.h"

char *ft_strnstr(const char *big, const char *little, size_t size)
{
    return ft_memmem(big, ft_strnlen(big, size), little, ft_strlen(little));
}
