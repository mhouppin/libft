#include "ft_barray.h"
#include "ft_math.h"

int barray_auto_expand(ByteArray *b)
{
    return barray_reserve(b, b->maxSize + ft_maxu(2 * ft_sqrtu(b->maxSize + 1) + 1, BARRAY_MIN_BYTE_ALLOC));
}
