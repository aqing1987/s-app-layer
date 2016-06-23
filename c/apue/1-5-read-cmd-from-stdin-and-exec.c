#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAXLINE 1024

int main(int argc, char *argv[])
{
    char buf[MAXLINE] = "";
    pid_t pid;
    int status = 0;

    // print prompt (printf requires %% to print %)
    printf("%% ");

    // char *fgets(char *s, int size, FILE *stream);
    while (fgets(buf, MAXLINE, stdin) != NULL) {
        if (buf[strlen(buf)-1] == '\n') {
            // replace newline with null
            buf[strlen(buf)-1] = '\0';
        }

        if ((pid = fork()) < 0) {
            perror("fork");
            return -1;
        }
        else if (pid == 0) { // child process
            // int execlp(const char *file, const char *arg, ...);
            if (execlp(buf, buf, NULL) < 0) {
                printf("couldn't execute %s\n", buf);
                exit(125);
            }
        }

        // parent
        // pid_t waitpid(pid_t pid, int *status, int options);
        if ((pid = waitpid(pid, &status, 0)) < 0) {
            perror("waitpid");
            return -1;
        }

        printf("child process exit code = %d\n", WEXITSTATUS(status));

        printf("\n%% ");
    }
    return 0;
}
