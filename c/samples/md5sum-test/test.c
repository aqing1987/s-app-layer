#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#include "md5.h"

#define MAX_BUF_LEN   128

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("usage: %s <filename>\n", argv[0]);
        return -1;
    }

    const char *fname = argv[1];

    if (access(fname, F_OK) != 0) {
        printf("%s not exist\n", fname);
        return -1;
    }

    FILE *fp = fopen(fname, "r");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    char tmp[MAX_BUF_LEN];
    unsigned char decrypt[16];

    memset(tmp, 0, sizeof(tmp));
    memset(decrypt, 0, sizeof(decrypt));

    MD5_CTX md5;
    MD5_Init(&md5);

    size_t rbytes = 0;
    rbytes = fread(tmp, 1, MAX_BUF_LEN, fp);
    while (rbytes > 0) {
        MD5_Update(&md5, tmp, rbytes);
        memset(tmp, 0, sizeof(tmp));
        rbytes = fread(tmp, 1, MAX_BUF_LEN, fp);
    }
    MD5_Final(decrypt, &md5);

    fclose(fp);

    // check result
    int i;
    for (i = 0; i < 16; i++) {
        printf("%02x", decrypt[i]);
    }
    printf("\n");

    return 0;
}