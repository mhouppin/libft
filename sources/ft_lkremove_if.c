#include "ft_lklist.h"

size_t ft_lkremove_if(lklist_t *list, bool (*dataRemovePred)(const void *), void (*dataDtor)(void *))
{
    lknode_t *node = list->front;
    size_t count = 0;

    while (node)
    {
        lknode_t *next = node->next;

        if (dataRemovePred(node->data))
        {
            ft_lkerase(list, node, dataDtor);
            ++count;
        }

        node = next;
    }
    return count;
}
