/**
 * ./a.out &
 * [1]      7216
 * kill -USR1 7216
 * kill -USR2 7216
 * kill 7216
 */
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

static void sig_usr(int signo)
{
    if (signo == SIGUSR1) {
        printf("received SIGUSR1\n");
    } else if (signo == SIGUSR2) {
        printf("received SIGUSR2\n");
    } else {
        printf("received signal %d\n", signo);
    }
}

int main(int argc, char *argv[])
{
    if (signal(SIGUSR1, sig_usr) == SIG_ERR) {
        perror("can't catch SIGUSR1");
    }
    if (signal(SIGUSR2, sig_usr) == SIG_ERR) {
        perror("can't catch SIGUSR2");
    }

    for (;;) {
        pause();
    }

    return 0;
}
