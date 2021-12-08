#include "ft_heap.h"
#include "ft_prior_queue.h"

void pqueue_set_item_cmp(PriorQueue *pq, int (*cmp)(const void *, const void *))
{
    pq->cmp = cmp;

    if (pq->cmp != NULL)
        heap_make(pq->vec.data, pq->vec.itemSize, pq->vec.itemCount, pq->cmp);
}
