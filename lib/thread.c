#include "thread.h"

void* thread_run(void *arg)
{
    do {

        /* main loop */

    } while(1);
}

void thread_init(struct thread *task)
{
    memset(task, 0, sizeof(struct thread));

    pthread_metux_init(&task->mx);
    pthread_cond_init(&task->cond, NULL);
}

void thread_destroy(struct thread *task)
{
    pthread_metux_destroy(&task->mx);
    pthread_cond_destroy(&task->cond);
}

