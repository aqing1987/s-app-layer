#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char** argv)
{
    int fd;
    char* buf;
    int i;

    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return -1;
    }

    const char *fname = argv[1];

    // get file status
    // fstat，lstat，chmod，chown，readlink，utime
    struct stat statbuf;
    if (stat(fname, &statbuf) < 0) {
        perror("stat");
        return -1;
    }

    fd = open(fname, O_RDONLY);
    if (fd < 0) {
        perror("open");
        return -1;
    }

    // mmap file to memory
    // void *mmap(void *addr, size_t length, int prot, int flags,
    //            int fd, off_t offset);
    // PROT_READ  Pages may be read.
    // MAP_PRIVATE Create a private copy-on-write mapping.
    buf = (char*)mmap(NULL, statbuf.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (buf == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return -1;
    }

    // get file content from memory
    i = 0;
    while (i < statbuf.st_size) {
        printf("%c", buf[i++]);
    }
    printf("\n");

    // unmmap
    // int munmap(void *addr, size_t length);
    if (munmap(buf, statbuf.st_size) < 0) {
        perror("munmap");
        close(fd);
        return -1;
    }

    close(fd);

    return 0;
}
