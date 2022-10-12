#include <stdlib.h>
#include "ft_list.h"

void list_pop_front(List *list, void (*dataDtor)(void *))
{
    if (list->size == 0)
        return ;

    if (dataDtor != NULL)
        dataDtor(list->front->data);

    if (list->size == 1)
    {
        free(list->front);
        list_init(list);
        return ;
    }

    ListNode *newFront = list->front->next;
    newFront->prev = NULL;
    free(list->front);
    list->front = newFront;
    --list->size;
}
