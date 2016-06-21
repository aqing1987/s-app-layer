#include <stdio.h>
#include <stdlib.h>

// atexit - register a function to be called at normal process termination
// int atexit(void (*function)(void));

void exit_f1(void)
{
    printf("exit f1\n");
}

void exit_f2(void)
{
    printf("exit f2\n");
}

int main(int argc, char *argv[])
{
    if (atexit(exit_f1) != 0) {
        perror("atexit");
    }

    if (atexit(exit_f2) != 0) {
        perror("atexit");
    }

    return 0;
}
