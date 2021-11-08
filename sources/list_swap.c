#include "ft_list.h"

void list_swap(List *list, List *other)
{
    List tmp = *list;
    *list = *other;
    *other = tmp;
}
