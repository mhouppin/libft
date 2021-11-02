#include "ft_queue.h"

int ft_qwrite(Queue *q, void *buf, size_t bufSize)
{
    pthread_mutex_lock(&q->mutex);

    if (ft_bpush_back_range(&q->buffer, &bufSize, sizeof(size_t)))
    {
        pthread_mutex_unlock(&q->mutex);
        return -1;
    }

    if (ft_bpush_back_range(&q->buffer, buf, bufSize))
    {
        ft_berase_range(&q->buffer, q->buffer.size - sizeof(size_t), q->buffer.size);
        pthread_mutex_unlock(&q->mutex);
        return -1;
    }

    pthread_mutex_unlock(&q->mutex);
    pthread_cond_broadcast(&q->cond);
    return 1;
}
