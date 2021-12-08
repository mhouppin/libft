#include "ft_prior_queue.h"

void pqueue_swap(PriorQueue *pq, PriorQueue *other)
{
    PriorQueue tmp;

    tmp = *pq;
    *pq = *other;
    *other = tmp;
}
