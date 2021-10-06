#include "ft_lklist.h"

void ft_lkmerge(List *list, List *other, int (*dataComp)(const void *, const void *))
{
    ListNode *topL = list->front;
    ListNode *topO = other->front;

    while (topL != NULL && topO != NULL)
    {
        if (dataComp(topO, topL) < 0)
        {
            ListNode *next = topO->next;
            ft_lksplice_one(list, topL, other, topO);
            topO = next;
        }
        else
            topL = topL->next;
    }

    if (topO != NULL)
        ft_lksplice_all(list, NULL, other);
}
