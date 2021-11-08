#include "ft_list.h"

int list_emplace(List *list, ListNode *pos, void *data)
{
    ListNode *node = list_node_create(data);

    if (node == NULL)
        return -1;

    list_insert(list, pos, node);
    return 0;
}
