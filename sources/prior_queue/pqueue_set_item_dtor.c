#include "ft_prior_queue.h"

void pqueue_set_item_dtor(PriorQueue *pq, void (*itemDtor)(void *))
{
    vector_set_item_dtor(&pq->vec, itemDtor);
}
