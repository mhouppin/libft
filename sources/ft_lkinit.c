#include "ft_list.h"

void ft_lkinit(List *list)
{
    list->front = NULL;
    list->back = NULL;
    list->size = 0;
}
