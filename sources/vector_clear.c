#include "ft_vector.h"

void vector_clear(Vector *vec)
{
    if (vec->itemDtor)
        for (size_t i = 0; i < vec->itemCount; ++i)
            vec->itemDtor(vector_at(vec, i));

    vec->itemCount = 0;
}
