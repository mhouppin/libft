#include <stdlib.h>
#include "ft_stdlib.h"
#include "ft_string.h"

static void mergesort_internal(void *base, void *buffer, size_t start, size_t end,
            size_t itemSize, int (*compar)(const void *, const void *))
{
    if (start + 1 >= end)
        return ;

    size_t middle = (start + end) / 2;
    mergesort_internal(buffer, base, start, middle, itemSize, compar);
    mergesort_internal(buffer, base, middle, end, itemSize, compar);

    size_t left = start;
    size_t right = middle;

    for (size_t i = start; i < end; ++i)
    {
        if (left < middle && (right >= end
                || compar((char *)buffer + left * itemSize, (char *)buffer + right * itemSize) <= 0))
        {
            ft_memcpy((char *)base + i * itemSize, (char *)buffer + left * itemSize, itemSize);
            ++left;
        }
        else
        {
            ft_memcpy((char *)base + i * itemSize, (char *)buffer + right * itemSize, itemSize);
            ++right;
        }
    }
}

int ft_mergesort(void *base, size_t nItems, size_t itemSize, int (*compar)(const void *, const void *))
{
    if (!nItems || !itemSize)
        return 0;

    void *buffer = malloc(nItems * itemSize);

    if (buffer == NULL)
        return -1;

    ft_memcpy(buffer, base, nItems * itemSize);
    mergesort_internal(base, buffer, 0, nItems, itemSize, compar);
    free(buffer);
    return 0;
}
