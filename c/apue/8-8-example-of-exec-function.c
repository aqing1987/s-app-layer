/**
 * Note:
 *    put echoall to /usr/bin first
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char *env_init[] = { "USER=unknow", "PATH=/tmp", NULL };

int main(int argc, char *argv[])
{
    pid_t pid;

    if ((pid = fork()) < 0) {
        perror("fork1");
        return -1;
    } else if (pid == 0) {
        // specify pathname, specify environment
        if (execle("/usr/bin/echoall", "echoall", "myarg1",
                   "MY ARG2", (char *)0, env_init) < 0) {
            perror("execle err");
        }
    }

    if (waitpid(pid, NULL, 0) < 0) {
        perror("waitpid err");
    }

    if ((pid = fork()) < 0) {
        perror("fork2");
        return -1;
    } else if (pid == 0) {
        // specify filename, inherit environment
        if (execlp("echoall", "echoall", "only 1 arg", (char *)0) < 0) {
            perror("execlp err");
        }
    }

    return 0;
}
