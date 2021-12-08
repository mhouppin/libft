#include "ft_string.h"

char *ft_strstr(const char *big, const char *little)
{
    return ft_memmem(big, ft_strlen(big), little, ft_strlen(little));
}
