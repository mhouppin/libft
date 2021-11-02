#include "ft_queue.h"

void ft_qdestroy(Queue *q)
{
    ft_bdestroy(&q->buffer);
    q->count = 0;
    pthread_cond_destroy(&q->cond);
    pthread_mutex_destroy(&q->mutex);
}
