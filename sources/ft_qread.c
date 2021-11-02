#include <stdlib.h>
#include "ft_queue.h"
#include "ft_string.h"

int ft_qread(Queue *q, void **buf, size_t *bufSize)
{
    pthread_mutex_lock(&q->mutex);

    if (!q->count)
    {
        pthread_mutex_unlock(&q->mutex);
        return 0;
    }

    size_t size = *(size_t *)q->buffer.data;

    if (size > *bufSize)
    {
        void *newPtr = malloc(size);

        if (newPtr == NULL)
        {
            pthread_mutex_unlock(&q->mutex);
            return -1;
        }

        free(*buf);
        *buf = newPtr;
        *bufSize = size;
    }

    ft_memcpy(*buf, q->buffer.data + sizeof(size_t), size);
    ft_berase_range(&q->buffer, 0, sizeof(size_t) + size);
    --q->count;
    pthread_mutex_unlock(&q->mutex);
    pthread_cond_broadcast(&q->cond);

    return 1;
}
