/**
 * a race condition occurs when multiple processes are trying to
 * do something with shared data and the final outcome depends
 * on the order in which the processes run.
 */
#include <stdio.h>
#include <unistd.h>

static void charatatime(const char *str)
{
    char *ptr;
    int c;

    setbuf(stdout, NULL); // set unbuffered
    for (ptr = str; (c = *ptr++) != 0; ) {
        putc(c, stdout);
    }
}

int main(int argc, char *argv[])
{
    pid_t pid;

    if ((pid = fork()) < 0) {
        perror("fork");
        return -1;
    } else if (pid == 0) {
        charatatime("output from child\n");
    } else {
        charatatime("output from parent\n");
    }

    return 0;
}
