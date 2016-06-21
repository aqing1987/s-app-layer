#include <stdio.h>

#define SD_MOUNT_PATH           "/storage"
#define EXTERNAL_MOUNT_PATH     "/external"
#define STORAGE_DIR             "xxx"

#define FULL_TF_MOUNT_DIR       SD_MOUNT_PATH"/"STORAGE_DIR"/"
#define FULL_USB_MOUNT_DIR      EXTERNAL_MOUNT_PATH"/"STORAGE_DIR"/"

int main(int argc, char *argv[])
{
    printf("full tf dir is %s\n", FULL_TF_MOUNT_DIR);
    printf("full usb dir is %s\n", FULL_USB_MOUNT_DIR);

    return 0;
}
