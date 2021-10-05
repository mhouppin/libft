#include "ft_lklist.h"

void ft_lkfirst_node(lklist_t *list, lknode_t *node)
{
    list->front = list->back = node;
    list->size = 1;
}
