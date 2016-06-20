/**
 * @file   1-2-cp-in-to-out.c
 * @brief  copy standard input to standart output
 *
 * usage1: ./a.out > data
 * usage2: ./a.out < infile > outfile
 *
 * @author re-x
 * @date   2016-06-20
 */
#include <stdio.h>
#include <unistd.h>

#define BUF_SIZE 4096

int main(int argc, char *argv[])
{
    int n = 0;
    char buf[BUF_SIZE] = "";

    while ((n = read(STDIN_FILENO, buf, BUF_SIZE)) > 0) {
        if (write(STDOUT_FILENO, buf, n) != n) {
            perror("write");
            return -1;
        }
    }
    if (n < 0) {
        perror("read");
        return -1;
    }

    return 0;
}
