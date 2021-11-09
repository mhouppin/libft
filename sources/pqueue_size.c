#include "ft_prior_queue.h"

size_t pqueue_size(const PriorQueue *pq)
{
    return vector_size(&pq->vec);
}
