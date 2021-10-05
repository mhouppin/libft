#include <stdlib.h>
#include "ft_lklist.h"

lknode_t *ft_lknode_create(void *data)
{
    lknode_t *node = malloc(sizeof(lknode_t));
    if (node == NULL)
        return NULL;

    node->data = data;
    node->prev = node->next = NULL;
    return node;
}
