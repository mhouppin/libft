#include "ft_heap.h"

int heap_is_ok(const void *first, size_t itemSize, size_t size, int (*cmp)(const void *, const void *))
{
    return heap_is_ok_until(first, itemSize, size, cmp) == size;
}
