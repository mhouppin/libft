#include "ft_lklist.h"

void ft_lkswap(lklist_t *list, lklist_t *other)
{
    lklist_t tmp = *list;
    *list = *other;
    *other = tmp;
}
