#include "ft_list.h"

int list_emplace_back(List *list, void *data)
{
    ListNode *node = list_node_create(data);

    if (node == NULL)
        return -1;
    list_push_back(list, node);
    return 0;
}
