#include "ft_string.h"
#include "ft_vector.h"

void vector_pop_front(Vector *vec)
{
    if (vec->itemDtor)
        vec->itemDtor(vec->data);
    --vec->itemCount;
    ft_memmove(vec->data, (char *)vec->data + vec->itemSize, vec->itemCount * vec->itemSize);
}
