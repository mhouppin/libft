#include "ft_mp_queue.h"

void mp_queue_init(MP_Queue *q)
{
    barray_init(&q->buffer);
    q->count = 0;
    pthread_mutex_init(&q->mutex, NULL);
    pthread_cond_init(&q->cond, NULL);
}
