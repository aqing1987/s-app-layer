#include <stdio.h>
#include <signal.h>
#include <errno.h>

static void pr_mask(const char *str)
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

    printf("\n");
    errno = errno_save;
}

int main(int argc, char *argv[])
{
    pr_mask("self blocked signals: ");

    return 0;
}
