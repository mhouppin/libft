#include "ft_vector.h"

void ft_vset_item_ctor(Vector *vec, void (*itemCtor)(void *))
{
    vec->itemCtor = itemCtor;
}
