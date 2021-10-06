#include "ft_string.h"
#include "ft_vector.h"

int ft_vresize(Vector *vec, size_t newSize)
{
    if (newSize <= vec->itemCount)
    {
        ft_verase_range(vec, newSize, vec->itemCount);
        return 0;
    }

    if (vec->maxItemCount < newSize && ft_vreserve(vec, newSize))
        return -1;

    if (vec->itemCtor)
        for (size_t i = vec->itemCount; i < newSize; ++i)
            vec->itemCtor(ft_vat(vec, i));

    else
        ft_bzero(ft_vat(vec, vec->itemCount), (newSize - vec->itemCount) * vec->itemSize);

    vec->itemCount = newSize;
    return 0;
}
