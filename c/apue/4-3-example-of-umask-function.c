/**
 * test cases:
 * $ umask # first print the current file mode creation mask
 * 002
 * $ ./a.out
 * -rw------- 1  0 Jul 11 22:59 foo2.out
 * -rw-rw-rw- 1  0 Jul 11 22:59 foo.out
 * $ umask # see if the file mode creation mask changed
 * 002
 */
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

int main(int argc, char *argv[])
{
    umask(0);

    if (creat("foo.out", RWRWRW) < 0) {
        perror("create foo.out");
        return -1;
    }

    // The value is expressed in octal, with one bit representing one
    // permission to be masked off.
    umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    if (creat("foo2.out", RWRWRW) < 0) {
        perror("create foo2.out");
        return -1;
    }

    return 0;
}
