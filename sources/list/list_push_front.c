#include "ft_list.h"

void list_push_front(List *list, ListNode *newNode)
{
    if (list->size == 0)
    {
        list_first_node(list, newNode);
        return ;
    }

    list->front->prev = newNode;
    newNode->next = list->front;
    list->front = newNode;
    ++list->size;
}
