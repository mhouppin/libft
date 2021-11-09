#include "ft_mp_queue.h"

void mp_queue_destroy(MP_Queue *q)
{
    barray_destroy(&q->buffer);
    q->count = 0;
    pthread_cond_destroy(&q->cond);
    pthread_mutex_destroy(&q->mutex);
}
