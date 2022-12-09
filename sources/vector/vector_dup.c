#include "ft_vector.h"

int vector_dup(Vector *dst, const Vector *src)
{
    return vector_init_cbuffer(dst, src->itemSize, src->itemCount, src->data);
}
