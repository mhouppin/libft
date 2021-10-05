#include "ft_lklist.h"

int ft_lkemplace(lklist_t *list, lknode_t *pos, void *data)
{
    lknode_t *node = ft_lknode_create(data);

    if (node == NULL)
        return -1;

    ft_lkinsert(list, pos, node);
    return 0;
}
