#include "ft_heap.h"

void heap_make(void *first, size_t itemSize, size_t size, int (*cmp)(const void *, const void *))
{
    if (size < 2)
        return ;

    size_t parent = (size - 2) / 2;

    while (1)
    {
        heap_adjust(first, itemSize, size, cmp, parent);

        if (parent == 0)
            break ;

        --parent;
    }
}
