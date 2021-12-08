#include "ft_mp_queue.h"

void mp_queue_wait_filled(MP_Queue *q)
{
    pthread_mutex_lock(&q->mutex);
    while (!q->count)
        pthread_cond_wait(&q->cond, &q->mutex);

    pthread_mutex_unlock(&q->mutex);
}
