/**
 * The getcwd function is useful when we have an application that
 * needs to return to the location in the file system where it started
 * out. We can save the starting location by calling getcwd before we
 * change our working directory. After we complete our processing, we
 * can pass the pathname obtained from getcwd to chdir to return to our
 * starting location in the file system.
 */
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define BUF_MAX_LEN 1024

int main(int argc, char *argv[])
{
    char path[BUF_MAX_LEN];

    memset(path, 0, BUF_MAX_LEN);

    //char *getcwd(char *buf, size_t size);
    if (chdir("/tmp") < 0) {
        perror("chdir");
        return -1;
    }

    if (getcwd(path, BUF_MAX_LEN) == NULL) {
        perror("getcwd");
        return -1;
    }

    printf("cwd = %s\n", path);

    return 0;
}
