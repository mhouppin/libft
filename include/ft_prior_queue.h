#ifndef FT_PRIOR_QUEUE_H
# define FT_PRIOR_QUEUE_H

# include "ft_vector.h"

typedef struct PriorQueue_
{
    Vector vec;
    int (*cmp)(const void *, const void *);
}
PriorQueue;

void pqueue_destroy(PriorQueue *pq);
int pqueue_empty(const PriorQueue *pq);
void pqueue_init(PriorQueue *pq, size_t itemSize, int (*cmp)(const void *, const void *));
void pqueue_pop(PriorQueue *pq, void *item);
int pqueue_push(PriorQueue *pq, const void *item);
void pqueue_set_item_cmp(PriorQueue *pq, int (*cmp)(const void *, const void *));
void pqueue_set_item_dtor(PriorQueue *pq, void (*itemDtor)(void *));
size_t pqueue_size(const PriorQueue *pq);
void pqueue_swap(PriorQueue *pq, PriorQueue *other);

#endif
