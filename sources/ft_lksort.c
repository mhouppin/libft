#include "ft_lklist.h"

void ft_lksort(lklist_t *list, int (*dataComp)(const void *, const void *))
{
    if (list->size < 2)
        return ;

    lklist_t carry;
    lklist_t bucket[64];
    lklist_t *fill = bucket;
    lklist_t *counter;

    do
    {
        ft_lksplice_one(&carry, carry.front, list, list->front);

        for (counter = bucket; counter != fill && counter->size > 0; ++counter)
        {
            ft_lkmerge(counter, &carry, dataComp);
            ft_lkswap(&carry, counter);
        }

        ft_lkswap(&carry, counter);

        if (counter == fill)
            ++fill;
    }
    while (list->size > 0);

    for (counter = bucket + 1; counter != fill; ++counter)
        ft_lkmerge(counter, counter - 1, dataComp);

    ft_lkswap(list, fill - 1);
}
