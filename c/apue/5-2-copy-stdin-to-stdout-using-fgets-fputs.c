#include <stdio.h>
#include <stdlib.h>

#define MAXLINE               1024
int main(int argc, char *argv[])
{
    char buf[MAXLINE];

    while (fgets(buf, MAXLINE, stdin) != NULL) {
        if (fputs(buf, stdout) == EOF) {
            perror("fputs err");
        }
    }

    if (ferror(stdin)) {
        printf("input err\n");
    }

    exit(0);
}
