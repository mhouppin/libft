#include "ft_heap.h"
#include "ft_prior_queue.h"

int pqueue_push(PriorQueue *pq, const void *item)
{
    if (vector_push_back(&pq->vec, item))
        return -1;

    if (pq->cmp != NULL)
        heap_push(pq->vec.data, pq->vec.itemSize, pq->vec.itemCount, pq->cmp);
    return 0;
}
