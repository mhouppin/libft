#include <stdlib.h>
#include "ft_vector.h"

void ft_vdestroy(Vector *vec)
{
    ft_vclear(vec);
    free(vec->data);
    vec->data = NULL;
    vec->maxItemCount = 0;
}
