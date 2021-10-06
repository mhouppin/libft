#include "ft_lklist.h"

int ft_lkemplace(List *list, ListNode *pos, void *data)
{
    ListNode *node = ft_lknode_create(data);

    if (node == NULL)
        return -1;

    ft_lkinsert(list, pos, node);
    return 0;
}
