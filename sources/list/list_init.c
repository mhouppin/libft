#include "ft_list.h"

void list_init(List *list)
{
    list->front = NULL;
    list->back = NULL;
    list->size = 0;
}
