#include "ft_list.h"

void list_sort(List *list, int (*dataComp)(const void *, const void *))
{
    if (list->size < 2)
        return ;

    List carry;
    List bucket[64];
    List *fill = bucket;
    List *counter;

    do
    {
        list_splice_one(&carry, carry.front, list, list->front);

        for (counter = bucket; counter != fill && counter->size > 0; ++counter)
        {
            list_merge(counter, &carry, dataComp);
            list_swap(&carry, counter);
        }

        list_swap(&carry, counter);

        if (counter == fill)
            ++fill;
    }
    while (list->size > 0);

    for (counter = bucket + 1; counter != fill; ++counter)
        list_merge(counter, counter - 1, dataComp);

    list_swap(list, fill - 1);
}
