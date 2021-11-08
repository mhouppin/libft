#include "ft_queue.h"

void queue_wait_filled(Queue *q)
{
    pthread_mutex_lock(&q->mutex);
    while (!q->count)
        pthread_cond_wait(&q->cond, &q->mutex);

    pthread_mutex_unlock(&q->mutex);
}
