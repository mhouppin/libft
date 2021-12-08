#include "ft_math.h"
#include "ft_vector.h"

int vector_auto_expand(Vector *vec)
{
    size_t minAllocs = (VECTOR_MIN_BYTE_ALLOC - 1) / vec->itemSize + 1;

    return vector_reserve(vec, vec->maxItemCount + ft_maxu(2 * ft_sqrtu(vec->maxItemCount) + 1, minAllocs));
}
