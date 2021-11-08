#include "ft_queue.h"

void queue_destroy(Queue *q)
{
    barray_destroy(&q->buffer);
    q->count = 0;
    pthread_cond_destroy(&q->cond);
    pthread_mutex_destroy(&q->mutex);
}
