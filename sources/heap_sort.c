#include "ft_heap.h"

void heap_sort(void *first, size_t itemSize, size_t size, int (*cmp)(const void *, const void *))
{
    while (size > 1)
    {
        --size;
        heap_pop(first, itemSize, size, cmp);
    }
}
