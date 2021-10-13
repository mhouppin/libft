#include "ft_barray.h"
#include "ft_string.h"

void ft_binit_str(ByteArray *b, char *str)
{
    ft_binit_buffer(b, str, ft_strlen(str) + 1);
}
