#include "ft_lklist.h"

void ft_lkmerge(lklist_t *list, lklist_t *other, int (*dataComp)(const void *, const void *))
{
    lknode_t *topL = list->front;
    lknode_t *topO = other->front;

    while (topL != NULL && topO != NULL)
    {
        if (dataComp(topO, topL) < 0)
        {
            lknode_t *next = topO->next;
            ft_lksplice_one(list, topL, other, topO);
            topO = next;
        }
        else
            topL = topL->next;
    }

    if (topO != NULL)
        ft_lksplice_all(list, NULL, other);
}
