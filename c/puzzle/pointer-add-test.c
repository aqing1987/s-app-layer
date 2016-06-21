#include <stdio.h>

int main()
{
    int *p = NULL;

    printf("p addr = 0x%x\n", p);
    // should be p+15*(sizeof(*p))
    printf("p + 15 addr = 0x%x\n", p+15);

    return 0;
}
