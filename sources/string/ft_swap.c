#include "ft_string.h"

void ft_swap(void *restrict left, void *restrict right, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        char tmp = ((char *)left)[i];
        ((char *)left)[i] = ((char *)right)[i];
        ((char *)right)[i] = tmp;
    }
}
