#include "ft_barray.h"
#include "ft_string.h"

int ft_binit_cstr(ByteArray *b, const char *str)
{
    return ft_binit_cbuffer(b, str, ft_strlen(str) + 1);
}
