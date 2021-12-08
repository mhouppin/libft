#include "ft_string.h"

char *ft_strtok(char *s, const char *delim)
{
    static char *oldptr;

    return ft_strtok_r(s, delim, &oldptr);
}
