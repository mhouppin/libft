#include <stdlib.h>
#include "ft_list.h"

void ft_lkdestroy(List *list, void (*dataDtor)(void *))
{
    ListNode *node = list->front;

    while (node != NULL)
    {
        ListNode *next = node->next;

        if (dataDtor != NULL)
            dataDtor(node->data);

        free(node);
        node = next;
    }
    list->front = list->back = NULL;
    list->size = 0;
}
