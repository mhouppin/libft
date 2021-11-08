#include <stdlib.h>
#include "ft_list.h"

void list_pop_back(List *list, void (*dataDtor)(void *))
{
    if (list->size == 0)
        return ;

    if (dataDtor != NULL)
        dataDtor(list->back->data);

    if (list->size == 1)
    {
        free(list->back);
        list_init(list);
        return ;
    }

    ListNode *newBack = list->back->prev;
    newBack->next = NULL;
    free(list->back);
    list->back = newBack;
    --list->size;
}
