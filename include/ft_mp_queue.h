#ifndef FT_MP_QUEUE_H
# define FT_MP_QUEUE_H

# include <pthread.h>
# include "ft_barray.h"

typedef struct MP_Queue_
{
    ByteArray buffer;
    size_t count;
    pthread_cond_t cond;
    pthread_mutex_t mutex;
}
MP_Queue;

void mp_queue_destroy(MP_Queue *q);
void mp_queue_init(MP_Queue *q);
int mp_queue_read(MP_Queue *q, void **buf, size_t *bufSize);
void mp_queue_wait_empty(MP_Queue *q);
void mp_queue_wait_filled(MP_Queue *q);
int mp_queue_write(MP_Queue *q, void *buf, size_t bufSize);

#endif
