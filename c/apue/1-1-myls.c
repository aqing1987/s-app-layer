#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *dirp;

    if (argc != 2) {
        printf("Usage: %s dirname\n", argv[0]);
        return -1;
    }

    dp = opendir(argv[1]);
    if (dp == NULL) {
        perror("opendir");
        return -1;
    }

    while ((dirp = readdir(dp)) != NULL) {
        printf("%s\n", dirp->d_name);
    }

    closedir(dp);

    return 0;
}
