#include "ft_list.h"

void list_splice_all(List *list, ListNode *pos, List *other)
{
    if (list->size == 0)
    {
        list_swap(list, other);
        return ;
    }

    list->size += other->size;

    if (pos == NULL)
    {
        list->back->next = other->front;
        other->front->prev = list->back;
        list->back = other->back;
    }
    else if (pos == list->front)
    {
        list->front->prev = other->back;
        other->back->next = list->front;
        list->front = other->front;
    }
    else
    {
        ListNode *prev = pos->prev;

        pos->prev = other->back;
        other->back->next = pos;
        prev->next = other->front;
        other->front->prev = prev;
    }

    list_init(other);
}
