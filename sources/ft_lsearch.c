#include "ft_stdlib.h"

void *ft_lsearch(const void *key, const void *base, size_t nItems, size_t itemSize, int (*compar)(const void *, const void *))
{
    for (size_t i = 0; i < nItems; i++)
    {
        if (compar(key, (char *)base + i * itemSize) == 0)
            return (char *)base + i * itemSize;
    }
    return NULL;
}
