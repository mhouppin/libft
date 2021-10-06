#include "ft_lklist.h"

void ft_lkswap(List *list, List *other)
{
    List tmp = *list;
    *list = *other;
    *other = tmp;
}
