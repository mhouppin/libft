#include "ft_barray.h"
#include "ft_math.h"

int barray_auto_expand(ByteArray *b)
{
    return barray_reserve(b, b->maxSize + ft_maxu(3 * b->maxSize / 2 + 1, BARRAY_MIN_BYTE_ALLOC));
}
