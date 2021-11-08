#include "ft_list.h"

ptrdiff_t list_distance(const ListNode *start, const ListNode *end)
{
    const ListNode *leftIt = start;
    const ListNode *rightIt = start;
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
