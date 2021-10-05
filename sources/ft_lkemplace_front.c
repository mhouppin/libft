#include "ft_lklist.h"

int ft_lkemplace_front(lklist_t *list, void *data)
{
    lknode_t *node = ft_lknode_create(data);

    if (node == NULL)
        return -1;
    ft_lkpush_front(list, node);
    return 0;
}
