#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    // char *strerror(int errnum);
    fprintf(stderr, "EACCESS: %s\n", strerror(EACCES));
    errno = ENOENT;

    // void perror(const char *s);
    perror(argv[0]);
    return 0;
}
