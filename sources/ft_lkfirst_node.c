#include "ft_list.h"

void ft_lkfirst_node(List *list, ListNode *node)
{
    list->front = list->back = node;
    list->size = 1;
}
