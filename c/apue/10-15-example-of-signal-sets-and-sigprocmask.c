/**
 * 1) $ ./a.out
 *      ^\            # generate signal once (before 5 seconds are up)
 *      SIGQUIT pending  # after return from sleep
 *      caught SIGQUIT   # in signal handler
 *      SIGQUIT unblocked # after return from sigprocmask
 *      ^\ quit (core dumped) # generate signal again
 * 2) $ ./a.out
 *      ^\ ^\ ^\ ^\   # generate signal 4 times (before 5 seconds are up)
 *
 * THe message Quit(coredump) is printed by the shell when it sees that its
 * child terminated abnormally. Note that when we run the program the second
 * time, we generate the quit signal 4 times while the process is asleep, yet
 * the signal is delivered only once to the process when it's unblocked.
 * This demonstrates that signals are not queued on this system.
 */
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

static void sig_quit(int signo)
{
    printf("caught SIGQUIT\n");

    if (signal(SIGQUIT, SIG_DFL) == SIG_ERR) {
        perror("cannot reset SIGQUIT");
    }
}

int main(int argc, char *argv[])
{
    sigset_t newmask, oldmask, pendmask;

    if (signal(SIGQUIT, sig_quit) == SIG_ERR) {
        perror("cannot catch SIGQUIT");
    }

    /**
     * Block SIGQUIT and save current signal mask
     */
    sigemptyset(&newmask);
    sigaddset(&newmask, SIGQUIT);
    if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0) {
        perror("SIG_BLOCK err");
    }

    sleep(5); // SIGQUIT here will remain pending

    if (sigpending(&pendmask) < 0) {
        perror("sigpending");
    }
    if (sigismember(&pendmask, SIGQUIT)) {
        printf("\n SIGQUIT pending\n");
    }

    /**
     * Reset signal mask which unblocks SIGQUIT
     */
    if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0) {
        perror("SIG_SETMASK err");
    }
    printf("SIGQUIT unblocked\n");

    sleep(5); // SIGQUIT here will terminate with core file

    return 0;
}
