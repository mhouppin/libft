#include "ft_lklist.h"

size_t ft_lkunique(lklist_t *list, bool (*dataBinaryPred)(const void *, const void *), void (*dataDtor)(void *))
{
    if (list->size < 2)
        return 0;

    lknode_t *node = list->front;
    size_t count = 0;

    while (node->next)
    {
        lknode_t *next = node->next;

        if (dataBinaryPred(node->data, next->data))
        {
            ft_lkerase(list, node, dataDtor);
            ++count;
        }

        node = next;
    }

    return count;
}