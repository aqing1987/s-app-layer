#include <stdio.h>

int main(int argc, char *argv[])
{
    int c = 0;

    // int getc(FILE *stream);
    while ((c = getc(stdin)) != EOF) {
        // int putc(int c, FILE *stream);
        if (putc(c, stdout) == EOF) {
            perror("putc error");
            return -1;
        }
    }

    if (ferror(stdin)) {
        perror("input error");
        return -1;
    }

    return 0;
}
