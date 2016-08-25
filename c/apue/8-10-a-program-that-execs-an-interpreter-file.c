/**
 * gcc 8-9-echo-all-command-line-arguments-and-all-environment-strings.c -o echoarg -g -Wall
 * cp echoarg /usr/bin
 * $ cat /usr/bin/testinterp
 * #!/usr/bin/echoarg foo
 *
 * Note that when the kernel exec the interpreter(/usr/bin/echoarg),
 * argv[0] is the pathname of the interpreter, argv[1] is the optional
 * argument from the interpreter file, and the remaining arguments are
 * the pathname (/usr/bin/testinterp) and the second and third arguments
 * from the all to execl in the program.
 *
 * same as:
 * /usr/bin/testinterp myarg1 "MY ARG2"
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    pid_t pid;

    pid = fork();
    if (pid < 0) {
        perror("fork");
        return -1;
    } else if (pid == 0) { //child
        if (execl("/usr/bin/testinterp", "testinterp",
                  "myarg1", "MY ARG2", (char*)0) < 0) {
            perror("execl");
        }
    }

    if (waitpid(pid, NULL, 0) < 0) { // parent
        perror("waitpid");
    }

    return 0;
}
