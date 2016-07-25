#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define TEST_FILE "./tempfile"

int main(int argc, char *argv[])
{
    if (open(TEST_FILE, O_RDWR | O_CREAT) < 0) {
        perror("open");
        return -1;
    }

    /**
     * This property of unlink is often used by a program
     * to ensure that a temporary file it creates won't be
     * left around in case the program crashes.
     * The process creates a file using either open or creat
     * and then immediately call unlink.
     * The file is not deleted, only when the process either
     * closes the file or terminates, which cause the kernel
     * to close all its open files.
     */
    if (unlink(TEST_FILE) < 0) {
        perror("unlink");
        return -1;
    }

    printf("%s unlinked\n", TEST_FILE);
    sleep(10);
    printf("done\n");

    return 0;
}
