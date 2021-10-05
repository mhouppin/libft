#include "ft_lklist.h"

void ft_lkreverse(lklist_t *list)
{
    lklist_t tmp;

    ft_lkinit(&tmp);

    while (list->back)
        ft_lksplice_one(&tmp, NULL, list, list->back);

    *list = tmp;
}
