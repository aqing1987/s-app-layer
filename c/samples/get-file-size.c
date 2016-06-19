#include <stdio.h>
#include <sys/stat.h>

unsigned long get_file_size(const char *path)
{
    unsigned long filesize = -1;
    struct stat statbuff;

    if (stat(path, &statbuff) == 0) {
        filesize = statbuff.st_size;
    }

    return filesize;
}

int main(int argc, char *argv[])
{
    unsigned long size = -1;

    if (argc != 2) {
        printf("Usage: %s filepath\n", argv[0]);
        return -1;
    }

    size = get_file_size(argv[1]);
    printf("size = %lu\n", size);

    return 0;
}
