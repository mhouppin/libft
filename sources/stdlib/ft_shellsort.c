#include <stdint.h>
#include <stdlib.h>
#include "ft_stdlib.h"
#include "ft_string.h"

static size_t sedgewick_value(size_t n)
{
    if (!n)
        return 1;

    size_t q = 4;
    size_t t = 1;

    for (size_t i = 0; i < n - 1; ++i)
    {
        q *= 4;
        t *= 2;
    }

    return q + 3 * t + 1;
}

int ft_shellsort(void *base, size_t nItems, size_t itemSize, int (*compar)(const void *, const void *))
{
    if (!nItems || !itemSize)
        return 0;

    void *tmp = malloc(itemSize);

    if (tmp == NULL)
        return -1;

    size_t n;

    for (n = 1; sedgewick_value(n) < nItems; ++n);

    while (--n)
    {
        size_t gap = sedgewick_value(n);

        for (size_t offset = 0; offset < gap; ++offset)
            for (size_t i = offset; i < nItems; i += gap)
            {
                ft_memcpy(tmp, (char *)base + i * itemSize, itemSize);

                size_t j;

                for (j = i; j >= gap && compar((char *)base + (j - gap) * itemSize, tmp) > 0; j -= gap)
                    ft_memcpy((char *)base + j * itemSize, (char *)base + (j - gap) * itemSize, itemSize);

                ft_memcpy((char *)base + j * itemSize, tmp, itemSize);
            }
    }

    free(tmp);
    return 0;
}
