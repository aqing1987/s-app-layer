#include <stdio.h>
#include <signal.h>
#include <errno.h>

void pr_mask(const char *str)
{
    sigset_t sigset;
    int errno_save;

    errno_save = errno; // we can be called by signal handlers

    if (sigprocmask(0, NULL, &sigset) < 0) {
        perror("sigprocmask");
        return;
    }

    printf("%s\n", str);

    if (sigismember(&sigset, SIGINT)) printf("SIGINT ");
    if (sigismember(&sigset, SIGQUIT)) printf("SIGQUIT ");
    if (sigismember(&sigset, SIGALRM)) printf("SIGALRM ");
    if (sigismember(&sigset, SIGUSR1)) printf("SIGUSR1 ");
    if (sigismember(&sigset, SIGUSR2)) printf("SIGUSR2 ");

    printf("\n");
    errno = errno_save;
}
