#include "ft_heap.h"

size_t heap_is_ok_until(const void *first, size_t itemSize, size_t size, int (*cmp)(const void *, const void *))
{
    size_t parent = 0;

    for (size_t child = 1; child < size; ++child)
    {
        if (cmp((const char *)first + itemSize * parent, (const char *)first + itemSize * child) > 0)
            return child;

        if (!(child & 1))
            ++parent;
    }

    return size;
}
