#include "ft_list.h"

void list_splice_one(List *list, ListNode *pos, List *other, ListNode *node)
{
    if (node == NULL)
        return ;

    if (node == other->front)
        other->front = other->front->next;
    else
        node->prev->next = node->next;

    if (node == other->back)
        other->back = other->back->prev;
    else
        node->next->prev = node->prev;

    node->next = NULL;
    node->prev = NULL;

    --other->size;

    list_insert(list, pos, node);
}
