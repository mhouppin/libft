#include "ft_lklist.h"

void ft_lkpush_back(List *list, ListNode *newNode)
{
    if (list->size == 0)
    {
        ft_lkfirst_node(list, newNode);
        return ;
    }

    list->back->next = newNode;
    newNode->prev = list->back;
    list->back = newNode;
    ++list->size;
}
