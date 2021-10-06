#include "ft_lklist.h"

void ft_lksplice_range(List *list, ListNode *pos, List *other, ListNode *first, ListNode *last)
{
    for (ListNode *node = first; node != last; )
    {
        ListNode *next = node->next;
        ft_lksplice_one(list, pos, other, node);
        node = next;
    }
}
