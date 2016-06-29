/**
 * 1) ./a.out
 * 2) ls -l file.hole # check its size
 *  8 -r-x--x--T 1 re-x re-x 16394 Jun 29 22:14 file.hole
 * 3) od -c file.hole # look at the actual contents
 * 0000000   a   b   c   d   e   f   g   h   i   j  \0  \0  \0  \0  \0  \0
 * 0000020  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0
 * *
 * 0040000   A   B   C   D   E   F   G   H   I   J
 * 4) dd if=/dev/zero of=./file.nohole bs=16394 count=1 # create a 16394 bytes file
 * 5) compare the file we've just created with a file of the same size, but without holes
 *  ls -ls file.*
 *  8 -r-x--x--T 1 xxx xxx 16394 Jun 29 22:14 file.hole
 *  20 -rw-rw-r-- 1 xxx xxx 16394 Jun 29 22:21 file.nohole
 * Although both files are the same size, the file without holes consumes 20
 * disk blocks, whereas the file with holes consumes only 8 blocks.
 * A hole in a file isn't required to have storage backing it on disk.
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

char g_buf1[] = "abcdefghij";
char g_buf2[] = "ABCDEFGHIJ";

int main(int argc, char *argv[])
{
    int fd;

    // int open(const char *pathname, int flags);
    if ((fd = open("./file.hole", O_CREAT | O_WRONLY | O_TRUNC)) == -1) {
        perror("open");
        return -1;
    }

    // ssize_t write(int fd, const void *buf, size_t count);
    if (write(fd, g_buf1, 10) != 10) {
        perror("write1");
        close(fd);
        return -1;
    }

    // offset now = 10
    // off_t lseek(int fd, off_t offset, int whence);
    if (lseek(fd, 16384, SEEK_SET) == -1) {
        perror("lseek");
        close(fd);
        return -1;
    }

    // offset now = 16384
    if (write(fd, g_buf2, 10) != 10) {
        perror("write2");
        close(fd);
        return -1;
    }
    // offset now = 16394

    return 0;
}
