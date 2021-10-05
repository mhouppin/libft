#include "ft_lklist.h"

ptrdiff_t ft_lkdistance(const lknode_t *start, const lknode_t *end)
{
    const lknode_t *leftIt = start;
    const lknode_t *rightIt = start;
    ptrdiff_t i = 0;

    while (leftIt != end && rightIt != end)
    {
        if (leftIt == NULL && rightIt == NULL)
            return 0;
        if (leftIt)
            leftIt = leftIt->prev;
        if (leftIt == rightIt)
            return 0;
        if (rightIt)
            rightIt = rightIt->prev;
        ++i;
    }

    return (rightIt == end) ? i : -i;
}
