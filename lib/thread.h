#ifndef __THREAD_H__
#define __THREAD_H__

#include <string.h>
#include <pthread.h>

struct thread {
    pthread_t id;
    pthread_t owner;
    pthread_mutex_t mx;
    pthread_cond_t cond;
    unsigned int req_cond;
};

extern void* thread_run(void *arg);
extern void thread_init(struct thread *task);
extern void thread_destroy(struct thread *task);

#endif
