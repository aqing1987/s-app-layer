#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#ifdef WCOREDUMP
unsigned char coredump_enable = 1;
#endif

static void pr_exit(int status)
{
    if (WIFEXITED(status)) {
        printf("normal termination, exit status = %d\n",
               WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
        if (coredump_enable) {
            printf("abnormal termination, signal number = %d%s\n",
                   WTERMSIG(status),
                   WCOREDUMP(status) ? " (core file generated)" : "");
        } else {
            printf("abnormal termination, signal number = %d\n",
                   WTERMSIG(status));
        }
    } else if (WIFSTOPPED(status)) {
        printf("child stopped, signal number = %d\n", WSTOPSIG(status));
    }
}

int main(int argc, char *argv[])
{
    int status;

    if ((status = system("date")) < 0) {
        perror("system");
    }
    pr_exit(status);

    if ((status = system("nosuchcommand")) < 0) {
        perror("system");
    }
    pr_exit(status);

    if ((status = system("who; exit 44")) < 0) {
        perror("system");
    }
    pr_exit(status);

    return 0;
}
