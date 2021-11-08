#include "ft_list.h"

size_t list_remove_if(List *list, bool (*dataRemovePred)(const void *), void (*dataDtor)(void *))
{
    ListNode *node = list->front;
    size_t count = 0;

    while (node)
    {
        ListNode *next = node->next;

        if (dataRemovePred(node->data))
        {
            list_erase(list, node, dataDtor);
            ++count;
        }

        node = next;
    }
    return count;
}
