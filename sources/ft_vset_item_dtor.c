#include "ft_vector.h"

void ft_vset_item_dtor(Vector *vec, void (*itemDtor)(void *))
{
    vec->itemDtor = itemDtor;
}
