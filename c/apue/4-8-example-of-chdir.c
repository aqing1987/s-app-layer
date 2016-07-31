/**
 * if we call by the sequence
 * $ pwd
 * /usr/lib
 * $ ./a.out
 * chdir to /tmp success
 * $ pwd
 * /usr/lib
 *
 * because it is an attribute of a process, the current working
 * directory cannot affect processes that invoke the process that
 * executes the chdir.
 */
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (chdir("/tmp") < 0) {
        perror("chdir");
        return -1;
    }

    printf("chdir to /tmp success\n");

    return 0;
}
