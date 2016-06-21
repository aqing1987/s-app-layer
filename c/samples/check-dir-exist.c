#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    struct stat statbuf;
    char *path = NULL;

    system("mkdir ./DDD; mkdir ./Ddd");

    path="./DDD";
    if (stat(path, &statbuf) != -1) {
        if (S_ISDIR(statbuf.st_mode)) {
            printf("%s exist.\n", path);
        }
    }
    else {
        printf("err! %s non-exist\n", path);
    }

    path="./Ddd";
    if (stat(path, &statbuf) != -1) {
        if (S_ISDIR(statbuf.st_mode)) {
            printf("%s exist.\n", path);
        }
    }
    else {
        printf("err! %s non-exist\n", path);
    }

    getchar();

    system("rm -rf ./DDD; rm -rf ./Ddd");

    return 0;
}



