#include "ft_vector.h"

void vector_set_item_dtor(Vector *vec, void (*itemDtor)(void *))
{
    vec->itemDtor = itemDtor;
}
