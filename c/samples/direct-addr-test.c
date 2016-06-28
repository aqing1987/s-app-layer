#include <stdio.h>

int main()
{
    int *ptr;

    ptr = (int *)0x8000;
    // may leads to Segmentation fault
    *ptr = 0xaabb;

    printf("%d\n", *ptr);

    return 0;
}
