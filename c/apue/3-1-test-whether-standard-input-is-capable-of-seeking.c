#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

// 1. can seek /dev/zero
// ./a.out < /dev/zero

// 2. cannot lseek pipe
// cat /proc/meminfo | ./a.out
int main(int argc, char *argv[])
{
    // off_t lseek(int fd, off_t offset, int whence);
    if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1) {
        printf("cannot seek\n");
    }
    else {
        printf("seek OK\n");
    }

    return 0;
}
