#include "ft_math.h"
#include "ft_vector.h"

int ft_vauto_expand(Vector *vec)
{
    size_t minAllocs = (VECTOR_MIN_BYTE_ALLOC - 1) / vec->itemSize + 1;

    return ft_vreserve(vec, vec->maxItemCount + ft_maxu(2 * ft_sqrtu(vec->maxItemCount) + 1, minAllocs));
}
