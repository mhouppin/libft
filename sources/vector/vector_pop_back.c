#include "ft_vector.h"

void vector_pop_back(Vector *vec)
{
    char *item = vector_at(vec, vec->itemCount - 1);

    if (vec->itemDtor)
        vec->itemDtor(item);
    --vec->itemCount;
}
