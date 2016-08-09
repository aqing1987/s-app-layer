#include <stdio.h>
#include <stdlib.h>

static void my_exit1(void)
{
    printf("first exit handler\n");
}

static void my_exit2(void)
{
    printf("second exit handler\n");
}

int main(int argc, char *argv[])
{
    if (atexit(my_exit2) != 0) {
        perror("atexit 2 handler");
        return -1;
    }

    if (atexit(my_exit1) != 0) {
        perror("atexit 1-1 handler");
        return -1;
    }

    if (atexit(my_exit1) != 0) {
        perror("atexit 1-2 handler");
        return -1;
    }

    printf("main is done\n");

    return 0;
}
