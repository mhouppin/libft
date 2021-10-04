#include "ft_stdio.h"
#include "ft_string.h"

int ft_dputendl(const char *s, int fd)
{
    size_t slen = ft_strlen(s);
    ssize_t result = write(fd, s, slen);

    if (result < (ssize_t)slen)
        return (result);

    result = ft_dputchar('\n', fd);

    return (result < 0) ? -1 : (int)(unsigned int)slen + result;
}
