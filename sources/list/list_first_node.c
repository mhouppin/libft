#include "ft_list.h"

void list_first_node(List *list, ListNode *node)
{
    list->front = list->back = node;
    list->size = 1;
}
