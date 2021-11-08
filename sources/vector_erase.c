#include "ft_string.h"
#include "ft_vector.h"

void vector_erase(Vector *vec, size_t index)
{
    char *item = vector_at(vec, index);

    if (vec->itemDtor)
        vec->itemDtor(item);
    --vec->itemCount;
    ft_memmove(item, item + vec->itemSize, (vec->itemCount - index) * vec->itemSize);
}
