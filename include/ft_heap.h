#ifndef FT_HEAP
# define FT_HEAP

# include <stddef.h>

void heap_adjust(void *first, size_t itemSize, size_t size, int (*cmp)(const void *, const void *), size_t index);
int heap_is_ok(const void *first, size_t itemSize, size_t size, int (*cmp)(const void *, const void *));
size_t heap_is_ok_until(const void *first, size_t itemSize, size_t size, int (*cmp)(const void *, const void *));
void heap_make(void *first, size_t itemSize, size_t size, int (*cmp)(const void *, const void *));
void heap_pop(void *first, size_t itemSize, size_t size, int (*cmp)(const void *, const void *));
void heap_push(void *first, size_t itemSize, size_t size, int (*cmp)(const void *, const void *));
void heap_push_internal(void *first, size_t itemSize, size_t holeIndex, size_t topIndex, int (*cmp)(const void *, const void *));
void heap_sort(void *first, size_t itemSize, size_t size, int (*cmp)(const void *, const void *));

#endif
