/**
 * test cases:
 * $ ./a.out 0 < /dev/tty
 * read only
 * $ ./a.out 1 > /tmp/foo
 * $ cat /tmp/foo
 * write only
 * $ ./a.out 2 2>>/tmp/foo
 * write only, append
 * $ ./a.out 5 5<>/tmp/foo
 * read write
 *
 * The clause 5<>temp.foo opens the file temp.foo for reading and writing
 * on file descriptor 5.
 */
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int val;

    if (argc != 2) {
        printf("Usage: %s <descriptor>\n", argv[0]);
        return -1;
    }

    // F_GETFL: Return the file status flags for filedes as the value
    // of the function.
    if ((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0) {
        printf("fcntl error for fd %d\n", atoi(argv[1]));
        return -1;
    }

    // the three access-mode flags — O_RDONLY , O_WRONLY , and O_RDWR
    // —are not separate bits that can be tested.
    // Therefore, we must first use the O_ACCMODE mask to obtain the
    // access-mode bits and then compare the result against any of the
    // three values.
    switch (val & O_ACCMODE) {
    case O_RDONLY:
        printf("read only");
        break;

    case O_WRONLY:
        printf("write only");
        break;

    case O_RDWR:
        printf("read write");
        break;

    default:
        printf("unknow access mode");
        break;
    }

    if (val & O_APPEND) {
        printf(", append");
    }

    if (val & O_NONBLOCK) {
        printf(", nonblocking");
    }

#if defined(O_SYNC)
    if (val & O_SYNC) {
        printf(", synchronous writes");
    }
#endif

#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC)
    if (val & O_FSYNC) {
        printf(", synchronous writes");
    }
#endif

    putchar('\n');

    return 0;
}
