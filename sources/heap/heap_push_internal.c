#include "ft_heap.h"
#include "ft_string.h"

void heap_push_internal(void *first, size_t itemSize, size_t holeIndex, size_t topIndex, int (*cmp)(const void *, const void *))
{
    size_t parent = (holeIndex - 1) / 2;

    while (holeIndex > topIndex && cmp(first + holeIndex * itemSize, first + parent * itemSize) < 0)
    {
        ft_swap(first + holeIndex * itemSize, first + parent * itemSize, itemSize);
        holeIndex = parent;
        parent = (holeIndex - 1) / 2;
    }
}
