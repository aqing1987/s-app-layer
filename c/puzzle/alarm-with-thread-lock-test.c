/**
 * @file   alarm-with-thread-lock-test.c
 * @brief  should not add mutex_lock in alarm handler, because
 *         alarm handler belongs to the same main thread, once
 *         pthread_mutex_lock continuously invoked twice, the
 *         app traps in deadlock situation.
 *
 * @author re-x
 * @date   2016-06-15
 */
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>

pthread_mutex_t lock;

/**
 * Untill alarm handler finised can main function run
 *
 * @param arg
 */
void alarm_handler(int arg)
{
    pthread_mutex_lock(&lock);
    printf("%s, called.\n", __func__);
    pthread_mutex_unlock(&lock);
}

int main(int argc, char *argv[])
{
    // signal() sets the disposition of the signal signum to handler
    signal(SIGALRM, alarm_handler);

    alarm(1);

    pthread_mutex_init(&lock, NULL);

    int num = 0;
    while (1) {
        pthread_mutex_lock(&lock);
        printf("\t%d\n", num++);
        sleep(3);
        pthread_mutex_unlock(&lock);
    }

    return 0;
}
