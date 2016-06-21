#include <stdio.h>

int main(int argc, char *argv[])
{
    int a = 21;
    int n = 4;

    printf("the %dth bit of a is %d\n", n, (a >> n) & 0x01);

    n = 3;
    printf("the %dth bit of a is %d\n", n, (a >> n) & 0x01);

    n = 2;
    printf("the %dth bit of a is %d\n", n, (a >> n) & 0x01);

    return 0;
}
