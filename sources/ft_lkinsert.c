#include "ft_lklist.h"

void ft_lkinsert(List *list, ListNode *pos, ListNode *newNode)
{
    if (pos == NULL)
    {
        ft_lkpush_back(list, newNode);
        return ;
    }

    if (pos == list->front)
    {
        ft_lkpush_front(list, newNode);
        return ;
    }

    ListNode *prev = pos->prev;
    if (prev != NULL)
        prev->next = newNode;

    newNode->prev = prev;
    pos->prev = newNode;
    newNode->next = pos;
    ++list->size;
}
