#ifndef FT_HEAP
# define FT_HEAP

# include <stddef.h>

/**
 * @brief Adjust the items' order in the heap.
 * @param first The first item of the heap.
 * @param itemSize The size of each item.
 * @param size The number of items in the heap.
 * @param cmp A pointer to a function that compares two items.
 * @param index The index of the item to adjust.
 * @ingroup heap_functions
*/
void heap_adjust(void *first, size_t itemSize, size_t size, int (*cmp)(const void *, const void *), size_t index);

/**
 * @brief Determines whether a range is a heap.
 * @param first The first item of the range.
 * @param itemSize The size of each item.
 * @param size The number of items in the range.
 * @param cmp A pointer to a function that compares two items.
 * @return 1 if the range is a heap, 0 otherwise.
 * @ingroup heap_functions
*/
int heap_is_ok(const void *first, size_t itemSize, size_t size, int (*cmp)(const void *, const void *));

/**
 * @brief Searches the end of a heap.
 * @param first The first item of the heap.
 * @param itemSize The size of each item.
 * @param size The number of items in the heap.
 * @param cmp A pointer to a function that compares two items.
 * @return The last index for which the heap property holds.
 * @ingroup heap_functions
*/
size_t heap_is_ok_until(const void *first, size_t itemSize, size_t size, int (*cmp)(const void *, const void *));

/**
 * @brief Builds a heap from a range.
 * @param first The first item of the range.
 * @param itemSize The size of each item.
 * @param size The number of items in the range.
 * @param cmp A pointer to a function that compares two items.
 * @ingroup heap_functions
*/
void heap_make(void *first, size_t itemSize, size_t size, int (*cmp)(const void *, const void *));

/**
 * @brief Moves the root of a heap to the top.
 * @param first The first item of the heap.
 * @param itemSize The size of each item.
 * @param size The number of items in the heap.
 * @param cmp A pointer to a function that compares two items.
 * @param item A pointer to a memory location where the removed item will be stored.
 * @ingroup heap_functions
*/
void heap_pop(void *first, size_t itemSize, size_t size, int (*cmp)(const void *, const void *));

/**
 * @brief Inserts an item into a heap.
 * @param first The first item of the heap.
 * @param itemSize The size of each item.
 * @param size The number of items in the heap.
 * @param cmp A pointer to a function that compares two items.
 * @ingroup heap_functions
*/
void heap_push(void *first, size_t itemSize, size_t size, int (*cmp)(const void *, const void *));

void heap_push_internal(void *first, size_t itemSize, size_t holeIndex, size_t topIndex, int (*cmp)(const void *, const void *));

/**
 * @brief Sorts a heap.
 * @param first The first item of the heap.
 * @param itemSize The size of each item.
 * @param size The number of items in the heap.
 * @param cmp A pointer to a function that compares two items.
 * @warning The heap loses its heap property.
 * @ingroup heap_functions
*/
void heap_sort(void *first, size_t itemSize, size_t size, int (*cmp)(const void *, const void *));

#endif
