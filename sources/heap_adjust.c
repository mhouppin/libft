#include "ft_heap.h"
#include "ft_string.h"

void heap_adjust(void *first, size_t itemSize, size_t size, int (*cmp)(const void *, const void *), size_t index)
{
    const size_t topIndex = index;
    size_t secondChild = index;

    while (secondChild < (size - 1) / 2)
    {
        secondChild = 2 * secondChild + 2;

        if (cmp(first + itemSize * secondChild, first + itemSize * (secondChild - 1)) < 0)
            secondChild--;

        ft_swap(first + itemSize * index, first + itemSize * secondChild, itemSize);
        index = secondChild;
    }

    if (!(size & 1) && secondChild == (size - 2) / 2)
    {
        secondChild = 2 * secondChild + 2;
        ft_swap(first + itemSize * index, first + itemSize * (secondChild - 1), itemSize);
        index = secondChild - 1;
    }

    heap_push_internal(first, itemSize, index, topIndex, cmp);
}
