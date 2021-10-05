#include "ft_lklist.h"

void ft_lksplice_all(lklist_t *list, lknode_t *pos, lklist_t *other)
{
    if (list->size == 0)
    {
        ft_lkswap(list, other);
        return ;
    }

    list->size += other->size;

    if (pos == NULL)
    {
        list->back->next = other->front;
        other->front->prev = list->back;
        list->back = other->back;
    }
    else if (pos == list->front)
    {
        list->front->prev = other->back;
        other->back->next = list->front;
        list->front = other->front;
    }
    else
    {
        lknode_t *prev = pos->prev;

        pos->prev = other->back;
        other->back->next = pos;
        prev->next = other->front;
        other->front->prev = prev;
    }

    ft_lkinit(other);
}
