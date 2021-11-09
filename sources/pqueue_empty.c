#include "ft_prior_queue.h"

int pqueue_empty(const PriorQueue *pq)
{
    return vector_size(&pq->vec) == 0;
}
