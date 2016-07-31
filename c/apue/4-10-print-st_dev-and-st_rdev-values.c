/**
 * Every file system is known by its major and minor device numbers, which
 * are encoded in the primitive system data type dev_t.
 * The major number identifies the device driver; the minor number identifies
 * the specific subdevice.
 * the st_dev value for every filename on a system is the device number
 * of the file system containing that filename and its corresponding
 * i-node.
 * Only character special files and block special files have an st_rdev
 * value. This value contains the device number for the actual device.
 *
 * e.g.
 * $ ./a.out /dev/tty[01]
 * /dev/tty0: dev = 0/6 (character) rdev = 4/0
 * /dev/tty1: dev = 0/6 (character) rdev = 4/1
 * Note that the filenames and i-nodes for the two terminal devices(st_dev)
 * are on device 0/6 - the devfs pseudo file system, which implemets the
 * /dev - but that their actual device numbers are 4/0 and 4/1.
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    int i;
    struct stat buf;

    for (i = 1; i < argc; i++) {
        printf("%s: ", argv[i]);

        if (stat(argv[i], &buf) < 0) {
            perror("stat");
            continue;
        }

        printf("dev = %d/%d ", major(buf.st_dev), minor(buf.st_dev));

        if (S_ISCHR(buf.st_mode) || S_ISBLK(buf.st_mode)) {
            printf("(%s) rdev = %d/%d",
                   (S_ISCHR(buf.st_mode)) ? "character" : "block",
                   major(buf.st_rdev), minor(buf.st_rdev));
        }

        printf("\n");
    }
    return 0;
}
