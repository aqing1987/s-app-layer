#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("hello world from process %d\n", getpid());
    return 0;
}
