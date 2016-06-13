#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    DIR *pdir = NULL;
    struct dirent *pdirent = NULL;
    char fname[256] = "";
    static int i = 0;

    if (argc != 2) {
        printf("Usage: %s dir\n", argv[0]);
        return -1;
    }

    pdir = opendir(argv[1]);
    if (pdir == NULL)
        return -1;

    while ((pdirent = readdir(pdir)) != NULL) {

        sprintf(fname, "%s/%s", argv[1], pdirent->d_name);
        printf("[%d] - %s\n", i++, fname);

        if (access(fname, F_OK) != 0) {
            printf("%s not exist.\n", fname);
            continue;
        }
    }
    closedir(pdir);

    return 0;
}
