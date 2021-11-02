#include "ft_queue.h"

void ft_qinit(Queue *q)
{
    ft_binit(&q->buffer);
    q->count = 0;
    pthread_mutex_init(&q->mutex, NULL);
    pthread_cond_init(&q->cond, NULL);
}
