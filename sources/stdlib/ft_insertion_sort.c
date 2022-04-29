#include <stdint.h>
#include <stdlib.h>
#include "ft_stdlib.h"
#include "ft_string.h"

int ft_insertion_sort(void *base, size_t nItems, size_t itemSize, int (*compar)(const void *, const void *))
{
    if (!nItems || !itemSize)
        return 0;

    void *tmp = malloc(itemSize);

    if (tmp == NULL)
        return -1;

    for (size_t i = 1; i < nItems; ++i)
    {
        ft_memcpy(tmp, (char *)base + i * itemSize, itemSize);

        size_t j = i - 1;

        while (j != SIZE_MAX && compar((char *)base + j * itemSize, (char *)base + i * itemSize) < 0)
        {
            ft_memcpy((char *)base + (j + 1) * itemSize, (char *)base + j * itemSize, itemSize);
            --j;
        }

        ++j;
        ft_memcpy((char *)base + j * itemSize, tmp, itemSize);
    }

    free(tmp);
    return 0;
}
