/**
 * Shows this situation: the parent process has forked a child that
 * stops, and the parent is about to exit.
 *
 * The child sends itself the stop signal(SIGTSTP) with the kill function.
 * This stops the child, similar to our stopping a foreground job with our
 * terminal's suspend character(Contrl-Z).
 * When the parent terminates, the child is orphaned
 * At this point, the child is now a member of an orphaned process group.
 * POSIX.1 requires that every process in the newly orphaned process group
 * that is stopped (as our child is) be sent the hang-up signal (SIGHUP)
 * followed by the continue signal (SIGCONT).
 * This causes the child to be continued, after processing the hang-up signal.
 * The default action for the hang-up signal is to terminate the process, so
 * we have to provide a signal handler to catch the signal. We therefore expect
 * the printf in the sig_hup function to appear before the printf in the
 * pr_ids function.
 */
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>

static void sig_hup(int signo)
{
    printf("SIGHUP received, pid = %d\n", getpid());
}

static void pr_ids(const char *name)
{
    printf("%s: pid = %d, ppid = %d, pgrp = %d, tpgrp = %d\n",
           name, getpid(), getppid(), getpgrp(), tcgetpgrp(STDIN_FILENO));
    fflush(stdout);
}

int main(int argc, char *argv[])
{
    char c;
    pid_t pid;

    pr_ids("parent");
    if ((pid = fork()) < 0) {
        perror("fork");
    } else if (pid > 0) { // parent
        sleep(5); // sleep to let child stop itself
        exit(0);  // then parent exits
    } else { // child
        pr_ids("child");
        signal(SIGHUP, sig_hup); // establish signal handler
        kill(getpid(), SIGTSTP); // stop ourself

        pr_ids("child"); // prints only if we're continued
        if (read(STDIN_FILENO, &c, 1) != 1) {
            printf("read error from controlling TTY, errno = %d\n", errno);
        }

        exit(0);
    }

    return 0;
}
