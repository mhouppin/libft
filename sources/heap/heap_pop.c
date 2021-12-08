#include "ft_heap.h"
#include "ft_string.h"

void heap_pop(void *first, size_t itemSize, size_t size, int (*cmp)(const void *, const void *))
{
    if (size == 1)
        return ;

    void *last = (char *)first + (size - 1) * itemSize;

    ft_swap(first, last, itemSize);
    heap_adjust(first, itemSize, size - 1, cmp, 0);
}
