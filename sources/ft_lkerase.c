#include <stdlib.h>
#include "ft_lklist.h"

void ft_lkerase(List *list, ListNode *node, void (*dataDtor)(void *))
{
    if (node == NULL)
        return ;

    if (node == list->front)
        list->front = list->front->next;
    else
        node->prev->next = node->next;

    if (node == list->back)
        list->back = list->back->prev;
    else
        node->next->prev = node->prev;

    if (dataDtor != NULL)
        dataDtor(node->data);

    free(node);
    --list->size;
}
