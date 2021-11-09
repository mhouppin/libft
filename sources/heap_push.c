#include "ft_heap.h"

void heap_push(void *first, size_t itemSize, size_t size, int (*cmp)(const void *, const void *))
{
    heap_push_internal(first, itemSize, size - 1, 0, cmp);
}
