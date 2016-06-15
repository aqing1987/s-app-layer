#include <stdio.h>
#include <unistd.h>
#include <signal.h>

/**
 * Untill alarm handler finised can main function run
 *
 * @param arg
 */
void alarm_handler(int arg)
{
    printf("%s, called.\n", __func__);
    sleep(5);
    printf("alarm, exit\n");
}

int main(int argc, char *argv[])
{
    // signal() sets the disposition of the signal signum to handler
    signal(SIGALRM, alarm_handler);

    alarm(3);

    int num = 0;
    while (1) {
        sleep(1);

        printf("\t%d\n", num++);
    }

    return 0;
}
