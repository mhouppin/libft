#include "ft_list.h"

size_t ft_lkunique(List *list, bool (*dataBinaryPred)(const void *, const void *), void (*dataDtor)(void *))
{
    if (list->size < 2)
        return 0;

    ListNode *node = list->front;
    size_t count = 0;

    while (node->next)
    {
        ListNode *next = node->next;

        if (dataBinaryPred(node->data, next->data))
        {
            ft_lkerase(list, node, dataDtor);
            ++count;
        }

        node = next;
    }

    return count;
}
