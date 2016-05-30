#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[])
{
      // strlen will compute '\n'
    char buf[8] = {
        'a', 'b', 'c', 'd',
        'e', 'f', 'g', '\n',
    };

      // strlen will not compute '\0'
    char buf2[8] = {
        'a', 'b', 'c', 'd',
        'e', 'f', 'g', '\0',
    };

    printf("strlen(buf) = %d\nsizeof(buf) = %ld\n",
           (int)strlen(buf), sizeof(buf));

    printf("strlen(buf2) = %d\nsizeof(buf2) = %ld\n",
           (int)strlen(buf2), sizeof(buf2));

    return 0;
}
