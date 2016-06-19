#include <stdio.h>
#include <string.h>

//size_t strlen(const char *s);

int main(int argc, char *argv[])
{
    char str_arr[3] = {'a', 'b', 'c'};

    printf("len of str_arr = %lu\n", strlen(str_arr));

    return 0;
}
