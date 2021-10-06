#include "ft_vector.h"

void ft_vclear(Vector *vec)
{
    if (vec->itemDtor)
        for (size_t i = 0; i < vec->itemCount; ++i)
            vec->itemDtor(ft_vat(vec, i));

    vec->itemCount = 0;
}
