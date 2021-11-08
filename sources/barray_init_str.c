#include "ft_barray.h"
#include "ft_string.h"

void barray_init_str(ByteArray *b, char *str)
{
    barray_init_buffer(b, str, ft_strlen(str) + 1);
}
