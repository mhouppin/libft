#include "ft_lklist.h"

void ft_lkpush_front(lklist_t *list, lknode_t *newNode)
{
    if (list->size == 0)
    {
        ft_lkfirst_node(list, newNode);
        return ;
    }

    list->front->prev = newNode;
    newNode->next = list->front;
    list->front = newNode;
    ++list->size;
}