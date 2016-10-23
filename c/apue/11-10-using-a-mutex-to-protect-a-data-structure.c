#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

struct foo {
    /**
     * when more than one thread needs to access a dynamically-allocated
     * object, we can embed a reference count in the object to ensure
     * that we don't free its memory before all threads are done using it.
     */
    int f_count;
    pthread_mutex_t f_lock;
};

static struct foo *g_foop = NULL;

static struct foo *foo_alloc(void)
{
    struct foo *fp;

    if ((fp = malloc(sizeof(struct foo))) != NULL) {
        fp->f_count = 1;
        if (pthread_mutex_init(&fp->f_lock, NULL) != 0) {
            free(fp);
            return NULL;
        }
    }

    return fp;
}

static void foo_hold(struct foo *fp)
{
    pthread_mutex_lock(&fp->f_lock);
    printf("ho:shared count = %d\n", fp->f_count);
    fp->f_count++;
    pthread_mutex_unlock(&fp->f_lock);
}

static void foo_rele(struct foo *fp)
{
    pthread_mutex_lock(&fp->f_lock);

    if (--fp->f_count == 0) { // last reference
        printf("re:shared count = %d\n", fp->f_count);
        pthread_mutex_unlock(&fp->f_lock);
        // if we allocate the mutex dynamically (by calling malloc)
        // then we need to call pthread_mutex_destroy before
        // freeing the memory
        pthread_mutex_destroy(&fp->f_lock);
        free(fp);
        g_foop = NULL;
    } else {
        printf("re:shared count = %d\n", fp->f_count);
        pthread_mutex_unlock(&fp->f_lock);
    }
}

static void *thr_fn1(void *arg)
{
    printf("thread 1 start\n");
    int i = 0;

    for (i = 0; i < 10; i++) {
        if (g_foop != NULL) {
            foo_hold(g_foop);
            sleep(1);
        }
    }

    printf("thread 1 end\n");
    return ((void *)1);
}

static void *thr_fn2(void *arg)
{
    printf("thread 2 start\n");
    int i = 0;

    for (i = 0; i < 2; i++) {
        if (g_foop != NULL) {
            foo_hold(g_foop);
            sleep(1);
        }
    }

    for (i = 0; i < 20; i++) {
        if (g_foop != NULL) {
            foo_rele(g_foop);
            sleep(1);
        }
    }

    printf("thread 2 end\n");
    pthread_exit((void *)2);
}

int main(int argc, char *argv[])
{
    int err;
    pthread_t tid1, tid2;

    void *tret;

    g_foop = foo_alloc();

    err = pthread_create(&tid1, NULL, thr_fn1, NULL);
    if (err != 0) {
        perror("create thread 1");
    }

    err = pthread_create(&tid2, NULL, thr_fn2, NULL);
    if (err != 0) {
        perror("create thread 2");
    }

    err = pthread_join(tid1, &tret);
    if (err != 0) {
        perror("join thread 1");
    }
    printf("thread 1 exit code %d\n", (int)tret);

    err = pthread_join(tid2, &tret);
    if (err != 0) {
        perror("join thread 2");
    }
    printf("thread 2 exit code %d\n", (int)tret);

    return 0;
}
