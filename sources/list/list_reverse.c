#include "ft_list.h"

void list_reverse(List *list)
{
    List tmp;

    list_init(&tmp);

    while (list->back)
        list_splice_one(&tmp, NULL, list, list->back);

    *list = tmp;
}
