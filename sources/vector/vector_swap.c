#include "ft_string.h"
#include "ft_vector.h"

void vector_swap(Vector *vec, Vector *other)
{
    if (vec == other)
        return ;

    ft_swap(vec, other, sizeof(Vector));
}
