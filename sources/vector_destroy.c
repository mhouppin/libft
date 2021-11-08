#include <stdlib.h>
#include "ft_vector.h"

void vector_destroy(Vector *vec)
{
    vector_clear(vec);
    free(vec->data);
    vec->data = NULL;
    vec->maxItemCount = 0;
}
