#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

void alarm_handler(int arg)
{
    char cmd[128];

    printf("%s, kill self!\n", __func__);

    sprintf(cmd, "kill -9 %d", getpid());
    system(cmd);
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

