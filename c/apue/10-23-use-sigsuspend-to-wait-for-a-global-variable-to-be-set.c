/**
 * Another use of sigsuspend is to wait for a signal handler to set a
 * global variable. We catch both the interrupt signal and the quit signal,
 * but want to wake up the main routine only when the quit signal is caught.
 */

#include <stdio.h>
#include <signal.h>

// set nonzero by signal handler
static volatile sig_atomic_t quitflag;

static void sig_int(int signo)
{
    if (signo == SIGINT) {
        printf("\ninterrupt\n");
    } else if (signo == SIGQUIT) {
        quitflag = 1; // set flag for main loop
    }
}

int main(int argc, char *argv[])
{
    sigset_t newmask, oldmask, zeromask;

    if (signal(SIGINT, sig_int) == SIG_ERR) {
        perror("signal SIGINT");
    }
    if (signal(SIGQUIT, sig_int) == SIG_ERR) {
        perror("signal SIGQUIT");
    }

    sigemptyset(&zeromask);
    sigemptyset(&newmask);

    sigaddset(&newmask, SIGQUIT);

    // block SIGQUIT and save current signal mask
    if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0) {
        perror("SIG_BLOCK err");
    }

    while (quitflag == 0) {
        sigsuspend(&zeromask);
    }

    // SIGQUIT has been caught and is now blocked, do whatever
    quitflag = 0;

    // reset signal mask which unblocks SIGQUIT
    if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0) {
        perror("SIG_SETMASK err");
    }

    return 0;
}
