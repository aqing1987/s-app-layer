#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/times.h>

// copy by using read write
static int cp_rw(int srcfd, int dstfd, char *buf, int len)
{
    int nread = 0;

    while ((nread = read(srcfd, buf, len)) > 0)
    {
        if (write(dstfd, buf, nread) != nread) {
            perror("write");
            return -1;
        }
    }

    if (nread == -1) {
        perror("read");
        return -1;
    }

    return 0;
}

// copy by using mmap, memcpy
static int cp_map(int srcfd, int dstfd, size_t len)
{
    char *src = NULL, *dst = NULL;

    src = mmap(0, len, PROT_READ, MAP_SHARED, srcfd, 0);
    if (src == MAP_FAILED) {
        perror("mmap src");
        return -1;
    }

    dst = mmap(0, len, PROT_WRITE, MAP_SHARED, dstfd, 0);
    if(dst == MAP_FAILED) {
        perror("mmap dst");
        return -1;
    }

    if (memcpy(dst, src, len) == NULL) {
        perror("memcpy");
        return -1;
    }

    munmap(src,len);
    munmap(dst,len);

    return 0;
}

static void test_read_write(const char *fsrc, const char *fdst)
{
    int srcfd, dstfd;
    int tck;
    clock_t start, end;
    struct tms stm,ntm;
    struct stat filestat;
    char buf[8192] = {0};

    tck = sysconf(_SC_CLK_TCK);
    start = times(&stm);
    if ((srcfd = open(fsrc, O_RDONLY)) == -1) {
        fprintf(stderr, "open %s error\n", fsrc);
        exit(1);
    }

    if ((dstfd = open(fdst, O_RDWR | O_CREAT | O_TRUNC, 0666)) == -1) {
        fprintf(stderr, "open %s error\n", fdst);
        exit(1);
    }

    cp_rw(srcfd, dstfd, buf, sizeof(buf));

    fstat(srcfd, &filestat);
    close(srcfd);
    close(dstfd);

    end = times(&ntm);
    printf("copying %s to %s using cp_rw:\n\tfilesize=%lu MBytes Using %f seconds\n",
           fsrc, fdst, filestat.st_size >> 20, (end-start)/(double)tck);
}

static void test_mmap_write(const char *fsrc, const char *fdst)
{
    int srcfd, dstfd;
    int tck;
    clock_t start, end;
    struct tms stm,ntm;
    struct stat filestat;

    if (fsrc == NULL || fdst == NULL) {
        printf("invalid parameter: fname\n");
        exit(1);
    }

    tck = sysconf(_SC_CLK_TCK);
    start = times(&stm);

    if ((srcfd = open(fsrc, O_RDONLY)) == -1) {
        fprintf(stderr, "open %s error\n", fsrc);
        exit(1);
    }
    if ((dstfd = open(fdst, O_RDWR | O_CREAT | O_TRUNC,0666)) == -1) {
        fprintf(stderr, "open %s error\n", fdst);
        exit(1);
    }

    // create empty file as source file size
    fstat(srcfd, &filestat);
    if (lseek(dstfd, filestat.st_size, SEEK_SET) == -1) {
        perror("lseek");
        exit(1);
    }
    if (write(dstfd, " ", 1) != 1) {
        perror("write ' '");
        exit(1);
    }

    cp_map(srcfd, dstfd, filestat.st_size);

    close(srcfd);
    close(dstfd);

    end = times(&ntm);
    printf("copying %s to %s using cp_map:\n\tfilesize=%lu MBytes Using %f seconds\n",
           fsrc, fdst, filestat.st_size >> 20, (end-start)/(double)tck);
}

int main(int argc,char **argv)
{
    if (argc != 3 || argv[1] == NULL || argv[2] == NULL) {
        printf("usage: %s src-file dst-file\n", argv[0]);
        return -1;
    }

    test_mmap_write(argv[1], argv[2]);
    test_read_write(argv[1], argv[2]);

    return 0;
}