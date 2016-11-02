#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

/**
 * int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
 *                  void *(*start_routine) (void *), void *arg);
 */
static int make_detached_thread(void *(*fn)(void *), void *arg)
{
    int err;
    pthread_t tid;
    pthread_attr_t attr;

    err = pthread_attr_init(&attr);
    if (err != 0) {
        return err;
    }

    err = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    if (err == 0) {
        err = pthread_create(&tid, &attr, fn, arg);
    }

    pthread_attr_destroy(&attr);

    return err;
}

static void *thr1(void *arg)
{
    int i = 0;

    for (i = 0; i < 10; i++) {
        printf("i = %d\n", i);
        sleep(1);
    }

    return (void *)0;
}

int main(int argc, char *argv[])
{
    make_detached_thread(thr1, NULL);

    sleep(1);

    /**
     * if main thread quit, thread tr1 still running
     * if process quit, all threads quit immediately
     */
#if 0
    int ret = 0;
    pthread_exit(&ret);
#endif

    printf("main quit\n");

    return 0;
}
