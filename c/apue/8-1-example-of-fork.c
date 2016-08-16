/**
 * testcases:
 * $ ./a.out
 * $ ./a.out > /tmp/xx ; cat /tmp/xx
 * In general, we never know whether the child starts executing before
 * the parent or vice versa.
 * Note the interaction of fork with the I/O functions `write' is not
 * buffered. Because `write' is called before the fork, its data is written
 * once to standard output. The standard I/O library, however, is buffered.
 * When we run the program interactively, we get only a single copy of the
 * printf line, because the standard output buffer is flushed by the newline.
 * But when we redirect standard output to a file, we get two copies of the
 * printf line.
 * In this second case, the printf before the fork is called once, but the
 * line remains in the buffer when fork is called. This buffer is then copied
 * into the child when the parent's data space is copied to the child.
 * Both the parent and the child now have a standard I/O buffer with this line
 * in it. The second printf, right before the exit, just appends its data to
 * the existing buffer. When each process terminates, its copy of the buffer
 * is finally flushed.
 */
#include <stdio.h>
#include <unistd.h>

int g_glob = 6;
char buf[] = "a write to stdout\n";

int main(int argc, char *argv[])
{
    int var;
    pid_t pid;

    var = 88;
    if (write(STDOUT_FILENO, buf, sizeof(buf)-1) != sizeof(buf)-1) {
        perror("write err");
        return -1;
    }
    printf("before fork\n"); // we don't flush stdout

    if ((pid = fork()) < 0) {
        perror("fork err");
        return -1;
    } else if (pid == 0) {
        // child
        g_glob++;
        var++;
    } else {
        // parent
        sleep(5);
    }

    printf("pid = %d, g_glob = %d, var = %d\n", getpid(), g_glob, var);

    return 0;
}
