#include <stdio.h>
#include <unistd.h>
#include <signal.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    char buf[BUF_SIZE] = "hello, world!\n";
    size_t size = 0;
    int count = 0;
    char *f_name = "/tmp/kkk";
    FILE *fp = NULL;

    fp = fopen(f_name, "a+");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    while (1) {
        printf("\t%4d\n", count++);
        if (count == 100) {
            break;
        }

        size = fwrite(buf, 1, BUF_SIZE, fp);
        if (size != BUF_SIZE) {
            perror("fwrite");
        }

        // For output streams, forces a write of all user-space buffered
        // data for the given output or update stream via the stream's
        // underlying write function.
        fflush(fp);
    }

    fclose(fp);

    return 0;
}
