#include <stdint.h>
#include <stdlib.h>
#include "ft_stdlib.h"
#include "ft_string.h"

static void ft_quicksort_r(void *base, size_t start, size_t end, size_t size, int (*compar)(const void *, const void *))
{
    if (start == SIZE_MAX || end == SIZE_MAX || start >= end)
        return ;

    size_t left = start - 1;
    size_t right = end + 1;
    void *pivot = (char *)base + (start + end) / 2 * size;

    while (1)
    {
        do
        {
            ++left;
        }
        while (compar((char *)base + left * size, pivot) < 0);

        do
        {
            ++right;
        }
        while (compar((char *)base + right * size, pivot) > 0);

        if (left >= right)
            break ;

        ft_swap((char *)base + left * size, (char *)base + right * size, size);
    }

    ft_quicksort_r(base, start, right, size, compar);
    ft_quicksort_r(base, right + 1, end, size, compar);
}

void ft_quicksort(void *base, size_t nItems, size_t itemSize, int (*compar)(const void *, const void *))
{
    if (nItems < 2 || itemSize == 0)
        return ;

    ft_quicksort_r(base, 0, nItems - 1, itemSize, compar);
    return ;
}
