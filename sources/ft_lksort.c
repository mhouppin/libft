#include "ft_lklist.h"

void ft_lksort(List *list, int (*dataComp)(const void *, const void *))
{
    if (list->size < 2)
        return ;

    List carry;
    List bucket[64];
    List *fill = bucket;
    List *counter;

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
