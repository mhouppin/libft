#include "ft_barray.h"
#include "ft_string.h"

int barray_init_cstr(ByteArray *b, const char *str)
{
    return barray_init_cbuffer(b, str, ft_strlen(str) + 1);
}
