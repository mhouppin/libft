#include "ft_lklist.h"

void ft_lksplice_range(lklist_t *list, lknode_t *pos, lklist_t *other, lknode_t *first, lknode_t *last)
{
    for (lknode_t *node = first; node != last; )
    {
        lknode_t *next = node->next;
        ft_lksplice_one(list, pos, other, node);
        node = next;
    }
}
