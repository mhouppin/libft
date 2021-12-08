#include "ft_prior_queue.h"

void pqueue_init(PriorQueue *pq, size_t itemSize, int (*cmp)(const void *, const void *))
{
    vector_init(&pq->vec, itemSize);
    pq->cmp = cmp;
}
