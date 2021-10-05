#include "ft_lklist.h"

void ft_lkinsert(lklist_t *list, lknode_t *pos, lknode_t *newNode)
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

    lknode_t *prev = pos->prev;
    if (prev != NULL)
        prev->next = newNode;

    newNode->prev = prev;
    pos->prev = newNode;
    newNode->next = pos;
    ++list->size;
}
