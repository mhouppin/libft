#include "ft_vector.h"

void vector_set_item_ctor(Vector *vec, void (*itemCtor)(void *))
{
    vec->itemCtor = itemCtor;
}
