#include "ft_heap.h"
#include "ft_prior_queue.h"
#include "ft_string.h"

void pqueue_pop(PriorQueue *pq, void *item)
{
    if (pq->cmp != NULL)
        heap_pop(pq->vec.data, pq->vec.itemSize, pq->vec.itemCount, pq->cmp);

    ft_memcpy(item, vector_at(&pq->vec, pq->vec.itemCount - 1), pq->vec.itemSize);
    --pq->vec.itemCount;
}
