#include "ft_barray.h"
#include "ft_stdio.h"

int ft_vasprintf(char **str, const char *fmt, va_list ap)
{
    ByteArray b;

    if (barray_init_vformat(&b, fmt, ap) || barray_push_back(&b, '\0'))
    {
        barray_destroy(&b);
        return -1;
    }

    *str = (char *)b.data;
    return b.size - 1;
}
