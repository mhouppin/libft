#include "ft_lklist.h"

void ft_lksplice_one(lklist_t *list, lknode_t *pos, lklist_t *other, lknode_t *node)
{
    if (node == NULL)
        return ;

    if (node == other->front)
        other->front = other->front->next;
    else
        node->prev->next = node->next;

    if (node == other->back)
        other->back = other->back->prev;
    else
        node->next->prev = node->prev;

    node->next = NULL;
    node->prev = NULL;

    --other->size;

    ft_lkinsert(list, pos, node);
}
