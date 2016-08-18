#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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
    pid_t pid;
    int status;

    if ((pid = fork()) < 0) {
        perror("fork 1");
    } else if (pid == 0) { // child
        exit(7);
    }

    // wait for child, and print its status
    if (wait(&status) != pid) {
        perror("wait err");
    }
    pr_exit(status);

    if ((pid = fork()) < 0) {
        perror("fork 2");
    } else if (pid == 0) {
        abort(); // generates SIGABRT
    }

    // wait for child, and print its status
    if (wait(&status) != pid) {
        perror("wait err");
    }
    pr_exit(status);

    if ((pid = fork()) < 0) {
        perror("fork 3");
    } else if (pid == 0) {
        status /= 0; // divide by 0 generates SIGFPE
    }

    // wait for child, and print its status
    if (wait(&status) != pid) {
        perror("wait err");
    }
    pr_exit(status);

    return 0;
}
