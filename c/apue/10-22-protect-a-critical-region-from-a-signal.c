#include <stdio.h>
#include <signal.h>

#include "utils.h"

static void sig_int(int signo)
{
    pr_mask("\nin sig_int: ");
}

int main(int argc, char *argv[])
{
    sigset_t newmask, oldmask, waitmask;

    pr_mask("program start: ");

    if (signal(SIGINT, sig_int) == SIG_ERR) {
        perror("signal SIGINIT");
    }

    sigemptyset(&waitmask);
    sigaddset(&waitmask, SIGUSR1);

    sigemptyset(&newmask);
    sigaddset(&newmask, SIGINT);

    // block SIGINT and save current signal mask
    if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0) {
        perror("sigprocmask");
    }

    // critical region of code
    pr_mask("in critical region: ");

    /**
     * pause, allowing all signals except SIGUSR1
     *
     * when sigsuspend returns, it restores the signal mask to its
     * value befor the call.
     */
    if (sigsuspend(&waitmask) != -1) {
        perror("sigsuspend err");
    }

    pr_mask("after return from sigsuspend: ");

    // reset signal mask which unblocks SIGINT
    if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0) {
        perror("sigprocmask setmask");
    }

    // and continue processing...
    pr_mask("program exit: ");

    return 0;
}
