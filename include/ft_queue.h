#ifndef FT_QUEUE_H
# define FT_QUEUE_H

# include <pthread.h>
# include "ft_barray.h"

typedef struct Queue_
{
    ByteArray buffer;
    size_t count;
    pthread_cond_t cond;
    pthread_mutex_t mutex;
}
Queue;

void queue_destroy(Queue *q);
void queue_init(Queue *q);
int queue_read(Queue *q, void **buf, size_t *bufSize);
void queue_wait_empty(Queue *q);
void queue_wait_filled(Queue *q);
int queue_write(Queue *q, void *buf, size_t bufSize);

#endif
