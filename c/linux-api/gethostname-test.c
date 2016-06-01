/**
 * man gethostname
 */
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char name[100];

    memset(name, 0, sizeof(name));

      /**
       * int gethostname(char *name, size_t len);
       */
    if (gethostname(name, sizeof(name)) < 0) {
        perror("gethostname");
        return -1;
    }

    printf("hostname is %s\n", name);

    return 0;
}
