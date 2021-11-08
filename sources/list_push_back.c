#include "ft_list.h"

void list_push_back(List *list, ListNode *newNode)
{
    if (list->size == 0)
    {
        list_first_node(list, newNode);
        return ;
    }

    list->back->next = newNode;
    newNode->prev = list->back;
    list->back = newNode;
    ++list->size;
}
