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

void ft_qdestroy(Queue *q);
void ft_qinit(Queue *q);
int ft_qread(Queue *q, void **buf, size_t *bufSize);
void ft_qwait_empty(Queue *q);
void ft_qwait_filled(Queue *q);
int ft_qwrite(Queue *q, void *buf, size_t bufSize);

#endif
