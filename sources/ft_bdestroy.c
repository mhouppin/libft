#include <stdlib.h>
#include "ft_barray.h"

void ft_bdestroy(ByteArray *b)
{
    free(b->data);
    b->data = NULL;
    b->size = 0;
    b->maxSize = 0;
}
