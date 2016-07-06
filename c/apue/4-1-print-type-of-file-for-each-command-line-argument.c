/**
 * test case
 * mkfifo /tmp/tfifo
 * ./a.out /etc/passwd /etc /tmp/tfifo /dev/log /dev/tty /dev/sda2 /dev/cdrom
 * /etc/passwd: regular
 * /etc: directory
 * /tmp/tfifo: fifo
 * /dev/log: socket
 * /dev/tty: character special
 * /dev/sda2: block special
 * /dev/cdrom: symbolic link
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int i;
    struct stat buf;
    char *ptr;

    for (i = 1; i < argc; i++) {
        printf("%s: ", argv[i]);

        // lstat() is identical to stat(), except that if path is a symbolic
        // link, then the link itself is stat-ed, not the file that it refers
        // to.
        // int lstat(const char *path, struct stat *buf);
        if (lstat(argv[i], &buf) < 0) {
            perror("lstat");
            return -1;
        }

        if (S_ISREG(buf.st_mode)) {
            ptr = "regular";
        } else if (S_ISDIR(buf.st_mode)) {
            ptr = "directory";
        } else if (S_ISCHR(buf.st_mode)) {
            ptr = "character special";
        } else if (S_ISBLK(buf.st_mode)) {
            ptr = "block special";
        } else if (S_ISFIFO(buf.st_mode)) {
            ptr = "fifo";
        } else if (S_ISLNK(buf.st_mode)) {
            ptr = "symbolic link";
        } else if (S_ISSOCK(buf.st_mode)) {
            ptr = "socket";
        } else {
            ptr = "** unknown mode **";
        }

        printf("%s\n", ptr);
    }

    return 0;
}
