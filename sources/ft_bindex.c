#include "ft_stdlib.h"

size_t ft_bindex(const void *key, const void *base, size_t nItems, size_t itemSize, int (*compar)(const void *, const void *))
{
    size_t left = 0;
    size_t right = nItems;

    while (left < right)
    {
        size_t index = (left + right) / 2;
        int result = compar(key, (const char *)base + index * itemSize);

        if (result < 0)
            right = index;
        else if (result > 0)
            left = index + 1;
        else
            return index;
    }

    return left;
}
