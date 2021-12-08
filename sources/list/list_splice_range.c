#include "ft_list.h"

void list_splice_range(List *list, ListNode *pos, List *other, ListNode *first, ListNode *last)
{
    for (ListNode *node = first; node != last; )
    {
        ListNode *next = node->next;
        list_splice_one(list, pos, other, node);
        node = next;
    }
}
