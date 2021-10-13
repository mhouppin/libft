#include "ft_barray.h"
#include "ft_stdio.h"

int ft_vdprintf(int fd, const char *restrict fmt, va_list ap)
{
    ByteArray b;

    if (ft_binit_vformat(&b, fmt, ap))
        return -1;

    int retval = write(fd, b.data, b.size);

    ft_bdestroy(&b);
    return retval;
}
