#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int ret = 0;

    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return -1;
    }

    ret = access(argv[1], F_OK);
    if (ret == 0) {
        printf("%s exist.\n", argv[1]);
    }
    else {
        printf("%s nonexistent.\n", argv[1]);
    }

    return 0;
}
