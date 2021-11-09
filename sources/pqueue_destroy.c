#include "ft_prior_queue.h"

void pqueue_destroy(PriorQueue *pq)
{
    vector_destroy(&pq->vec);
}
