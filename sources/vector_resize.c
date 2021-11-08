#include "ft_string.h"
#include "ft_vector.h"

int vector_resize(Vector *vec, size_t newSize)
{
    if (newSize <= vec->itemCount)
    {
        vector_erase_range(vec, newSize, vec->itemCount);
        return 0;
    }

    if (vec->maxItemCount < newSize && vector_reserve(vec, newSize))
        return -1;

    if (vec->itemCtor)
        for (size_t i = vec->itemCount; i < newSize; ++i)
            vec->itemCtor(vector_at(vec, i));

    else
        ft_bzero(vector_at(vec, vec->itemCount), (newSize - vec->itemCount) * vec->itemSize);

    vec->itemCount = newSize;
    return 0;
}
