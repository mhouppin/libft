#include "ft_list.h"

void list_merge(List *list, List *other, int (*dataComp)(const void *, const void *))
{
    ListNode *topL = list->front;
    ListNode *topO = other->front;

    while (topL != NULL && topO != NULL)
    {
        if (dataComp(topO, topL) < 0)
        {
            ListNode *next = topO->next;
            list_splice_one(list, topL, other, topO);
            topO = next;
        }
        else
            topL = topL->next;
    }

    if (topO != NULL)
        list_splice_all(list, NULL, other);
}
