#include <stdlib.h>
#include "ft_lklist.h"

void ft_lkpop_back(lklist_t *list, void (*dataDtor)(void *))
{
    if (list->size == 0)
        return ;

    if (dataDtor != NULL)
        dataDtor(list->back->data);

    if (list->size == 1)
    {
        free(list->back);
        ft_lkinit(list);
        return ;
    }

    lknode_t *newBack = list->back->prev;
    newBack->next = NULL;
    free(list->back);
    list->back = newBack;
    --list->size;
}
