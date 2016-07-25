/**
 * truncates files to zero length using the O_TRUNC option of the open
 * function, but does not change theier access time or modification time.
 * To do this, the program first obtains the times with the stat function,
 * truncates the file, and then resets the times with the utime function.

 * ls -l A B  # look at sizes and last-modification times
 * ls -lu A B # look at last-access times
 * date       # print today's date
 * ./a.out A B # run the program and check the results
 * ls -lu A B # check the last-access times also
 * ls -lc A B # and the changed-status times
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <utime.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int i, fd;
    struct stat statbuf;
    struct utimbuf timebuf;

    for (i = 1; i < argc; i++) {
        if (stat(argv[i], &statbuf) < 0) { // fetch current times
            perror("stat");
            continue;
        }

        // truncate
        if ((fd = open(argv[i], O_RDWR | O_TRUNC)) < 0) {
            perror("open");
            continue;
        }

        close(fd);

        timebuf.actime = statbuf.st_atime;
        timebuf.modtime = statbuf.st_mtime;
        if (utime(argv[i], &timebuf) < 0) { // reset times
            perror("utime");
            continue;
        }
    }

    return 0;
}
