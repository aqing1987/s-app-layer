/**
 * shows the problem with using an automatic variable (allocated
 * on the stack) as the argument to `pthread_exit'
 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

struct foo {
    int a, b, c, d;
};

static void printfoo(const char *s, const struct foo *fp)
{
    printf("%s", s);
    printf("\t structure at 0x%x\n", (unsigned)fp);
    printf("\tfoo.a = %d\n", fp->a);
    printf("\tfoo.b = %d\n", fp->b);
    printf("\tfoo.c = %d\n", fp->c);
    printf("\tfoo.d = %d\n", fp->d);
}

static void *thr_fn1(void *arg)
{
    struct foo foo = {1, 2, 3, 4};

    printfoo("thread 1:\n", &foo);
    pthread_exit((void *) &foo);
}

static void *thr_fn2(void *arg)
{
    printf("thread 2: ID is %d\n", pthread_self());
    pthread_exit((void *)0);
}

int main(int argc, char *argv[])
{
    int err;
    pthread_t tid1, tid2;
    struct foo *fp;

    err = pthread_create(&tid1, NULL, thr_fn1, NULL);
    if (err != 0) {
        perror("can't create thread 1\n");
    }

    err = pthread_join(tid1, (void *)&fp);
    if (err != 0) {
        perror("can't join thread 1\n");
    }

    sleep(1);

    printf("parent starting second thread\n");
    err = pthread_create(&tid2, NULL, thr_fn2, NULL);
    if (err != 0) {
        perror("can't create thread 2\n");
    }

    sleep(1);

    printfoo("parent:\n", fp);

    return 0;
}
