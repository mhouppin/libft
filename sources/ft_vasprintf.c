#include "ft_barray.h"
#include "ft_stdio.h"

int ft_vasprintf(char **str, const char *fmt, va_list ap)
{
    ByteArray b;

    if (ft_binit_vformat(&b, fmt, ap) || ft_bpush_back(&b, '\0'))
    {
        ft_bdestroy(&b);
        return -1;
    }

    *str = (char *)b.data;
    return b.size - 1;
}
