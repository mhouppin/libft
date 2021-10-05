#include "ft_lklist.h"

void ft_lkinit(lklist_t *list)
{
    list->front = NULL;
    list->back = NULL;
    list->size = 0;
}
