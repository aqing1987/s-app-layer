#include <stdio.h>

int main(int argc, char *argv[])
{
    char *p_str = "fdfdsfsddsafjsdkfjs;af";

    while (*p_str) {
        printf("-- %c\n", *p_str);

        if (*(p_str+1)) {
            printf(" [1] = %c, [2] = %c\n", *p_str, *(p_str+1));
        }

        p_str++;
    }

    return 0;
}

