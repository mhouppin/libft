#include "ft_list.h"

void list_insert(List *list, ListNode *pos, ListNode *newNode)
{
    if (pos == NULL)
    {
        list_push_back(list, newNode);
        return ;
    }

    if (pos == list->front)
    {
        list_push_front(list, newNode);
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
