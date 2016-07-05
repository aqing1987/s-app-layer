#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

// flags are file status flags to turn on
static int set_fl(int fd, int flags)
{
    int val;

    if ((val = fcntl(fd, F_GETFL, 0)) < 0) {
        printf("fcntl F_GETFL error");
        return -1;
    }

    // turn on flags
    val |= flags;

    if (fcntl(fd, F_SETFL, val) < 0) {
        printf("fcntl F_SETFL error");
        return -1;
    }
}

// flags are file status flags to turn off
static int clr_fl(int fd, int flags)
{
    int val;

    if ((val = fcntl(fd, F_GETFL, 0)) < 0) {
        printf("fcntl F_GETFL error");
        return -1;
    }

    // turn off flags
    val &= ~flags;

    if (fcntl(fd, F_SETFL, val) < 0) {
        printf("fcntl F_SETFL error");
        return -1;
    }
}
