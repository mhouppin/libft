#include "ft_barray.h"
#include "ft_math.h"

int ft_bauto_expand(ByteArray *b)
{
    return ft_breserve(b, ft_maxu(2 * ft_sqrtu(b->maxSize + 1) + 1, BARRAY_MIN_BYTE_ALLOC));
}
