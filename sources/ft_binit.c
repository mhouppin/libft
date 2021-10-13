#include "ft_barray.h"

void ft_binit(ByteArray *b)
{
    b->data = NULL;
    b->size = 0;
    b->maxSize = 0;
}
