#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;

int main(int argc, char **argv)
{
    char **env = environ;

    while (*env) {
        printf("%s\n", *env);
        env++;
    }
    printf("HOME: %s\n", getenv("HOME"));

    return 0;
}