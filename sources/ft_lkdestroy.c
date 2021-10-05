#include <stdlib.h>
#include "ft_lklist.h"

void ft_lkdestroy(lklist_t *list, void (*dataDtor)(void *))
{
    lknode_t *node = list->front;

    while (node != NULL)
    {
        lknode_t *next = node->next;

        if (dataDtor != NULL)
            dataDtor(node->data);

        free(node);
        node = next;
    }
    list->front = list->back = NULL;
    list->size = 0;
}
