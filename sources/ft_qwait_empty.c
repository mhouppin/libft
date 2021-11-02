#include "ft_queue.h"

void ft_qwait_empty(Queue *q)
{
    pthread_mutex_lock(&q->mutex);
    while (q->count)
        pthread_cond_wait(&q->cond, &q->mutex);

    pthread_mutex_unlock(&q->mutex);
}
