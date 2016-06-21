#include <stdio.h>

int main(int argc, char *argv[])
{
    int pass = 1023;
    int key = 999;
    int encrypted_ret = 0;

    encrypted_ret = pass ^ key;

    printf("encrypted pass is %d\n", encrypted_ret ^ key);

    return 0;
}
