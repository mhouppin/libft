#include "ft_list.h"

int ft_lkemplace_front(List *list, void *data)
{
    ListNode *node = ft_lknode_create(data);

    if (node == NULL)
        return -1;
    ft_lkpush_front(list, node);
    return 0;
}
