#include <stdlib.h>
#include "ft_list.h"

ListNode *list_node_create(void *data)
{
    ListNode *node = malloc(sizeof(ListNode));
    if (node == NULL)
        return NULL;

    node->data = data;
    node->prev = node->next = NULL;
    return node;
}
