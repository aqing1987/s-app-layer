#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static int disk_remount(const char *mount_point)
{
    char cmd[256];
    char disk_name[128];
    int len = 0;

    if (mount_point == NULL) {
        return -1;
    }

    // get disk partition name
    sprintf(cmd,
            "for dname in $(cat /proc/mounts | grep %s \
            | awk -F ' ' '{print $1}'); do ret=0;test -e $dname && ret=1; \
            done; echo $dname",
            mount_point);

    FILE *fd = popen(cmd, "r");
    if (fd == NULL) {
        perror("popen");
        return -1;
    }

    memset(disk_name, 0, sizeof(disk_name));
    fgets(disk_name, sizeof(disk_name)-1, fd);
    pclose(fd);

    // judge disk name
    len = strlen(disk_name);
    if (disk_name[len-1] == '\n') {
        disk_name[len-1] = '\0';
    }

    if (strlen(disk_name) == 0) {
        printf("no partition name got!\n");
        return -2;
    }

    printf("disk partition name is %s\n", disk_name);

    // remount disk partition to mount directory
    sprintf(cmd, "umount %s", disk_name);
    printf("cmd = %s\n", cmd);
    system(cmd);

    sprintf(cmd, "mount %s %s", disk_name, mount_point);
    printf("cmd = %s\n", cmd);
    system(cmd);

    return 0;
}

int main(int argc, char *argv[])
{
    int ret = 0;

    if (argc != 2) {
        printf("Usage: %s mount_dir\n", argv[0]);
        return -1;
    }

    if (access(argv[1], F_OK) != 0) {
        printf("mount point not exist.\n");
        return -2;
    }

    ret = disk_remount(argv[1]);
    if (ret < 0) {
        printf("disk remount err. ret = %d\n", ret);
    }

    return 0;
}
