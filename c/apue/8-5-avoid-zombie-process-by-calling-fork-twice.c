/**
 * If we want to write a process so that it forks a child but
 * we don't want to wait for the child to complete and we don't
 * want the child to become a zombie until we terminate, the
 * trick is to call fork twice.
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    pid_t pid;

    if ((pid = fork()) < 0) {
        perror("fork 1 err");
        return -1;
    } else if (pid == 0) { // first child
        if ((pid = fork()) < 0) {
            perror("fork 2 err");
        } else if (pid > 0) {
            exit(0); // parent from second fork == first child
        }

        /**
         * we're the second child; our parent becomes init as soon
         * as our real parent calls exit() in the statement above.
         * Here's where we'd continue executing, knowing that when
         * we're done, init will reap our status.
         */
        sleep(2);
        printf("second child, parent pid = %d\n", getppid());
        exit(0);
    }

    if (waitpid(pid, NULL, 0) != pid) { // wait for first child
        perror("waitpid");
    }

    /**
     * we're the parent (the original process); we continue
     * executing, knowing that we're not the parent of the
     * second child.
     */
    return 0;
}
