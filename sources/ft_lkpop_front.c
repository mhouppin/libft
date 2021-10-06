#include <stdlib.h>
#include "ft_lklist.h"

void ft_lkpop_front(List *list, void (*dataDtor)(void *))
{
    if (list->size == 0)
        return ;

    if (dataDtor != NULL)
        dataDtor(list->front->data);

    if (list->size == 1)
    {
        free(list->front);
        ft_lkinit(list);
        return ;
    }

    ListNode *newFront = list->front->next;
    newFront->next = NULL;
    free(list->front);
    list->front = newFront;
    --list->size;
}
