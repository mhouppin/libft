#include "ft_list.h"

int list_emplace_front(List *list, void *data)
{
    ListNode *node = list_node_create(data);

    if (node == NULL)
        return -1;
    list_push_front(list, node);
    return 0;
}
