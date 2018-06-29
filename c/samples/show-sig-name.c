#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: argv[0] signo\n");
        return -1;
    }

    char *p = NULL;
    p = strsignal(atoi(argv[1]));

    if (p == NULL) {
        printf("invalid signo\n");
        return -1;
    }

    printf("%s\n", p);

    return 0;
}
