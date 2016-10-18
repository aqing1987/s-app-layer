/**
 * If the thread terminates by returning from its start routine,
 * its cleanup handlers are not called.
 * The cleanup handlers are called in the reverse order from which
 * they were installed.
 */
#include <stdio.h>
#include <pthread.h>

static void cleanup(void *arg)
{
    printf("cleanup: %s\n", (char *)arg);
}

static void *thr_fn1(void *arg)
{
    printf("thread 1 start\n");
    pthread_cleanup_push(cleanup, "thread 1 first handler");
    pthread_cleanup_push(cleanup, "thread 1 second handler");
    printf("thread 1 push done\n");
    if (arg) {
        return ((void *)1);
    }

    pthread_cleanup_pop(0);
    pthread_cleanup_pop(0);
    return ((void *)1);
}

static void *thr_fn2(void *arg)
{
    printf("thread 2 start\n");
    pthread_cleanup_push(cleanup, "thread 2 first handler");
    pthread_cleanup_push(cleanup, "thread 2 second handler");
    printf("thread 2 push done\n");
    if (arg) {
        pthread_exit((void *)2);
    }

    pthread_cleanup_pop(0);
    pthread_cleanup_pop(0);
    pthread_exit((void *)2);
}

int main(int argc, char *argv[])
{
    int err;
    pthread_t tid1, tid2;
    void *tret;

    err = pthread_create(&tid1, NULL, thr_fn1, (void *)1);
    if (err != 0) {
        perror("thread 1 create");
    }

    err = pthread_create(&tid2, NULL, thr_fn2, (void *)1);
    if (err != 0) {
        perror("thread 2 create");
    }

    err = pthread_join(tid1, &tret);
    if (err != 0) {
        perror("join 1");
    }
    printf("thread 1 exit code %d\n", (int)tret);

    err = pthread_join(tid2, &tret);
    if (err != 0) {
        perror("join 2");
    }
    printf("thread 2 exit code %d\n", (int)tret);

    return 0;
}
