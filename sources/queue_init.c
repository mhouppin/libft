#include "ft_queue.h"

void queue_init(Queue *q)
{
    barray_init(&q->buffer);
    q->count = 0;
    pthread_mutex_init(&q->mutex, NULL);
    pthread_cond_init(&q->cond, NULL);
}
