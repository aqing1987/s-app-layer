/**
 * fgets() reads in at most one less than size characters from stream
 * and stores them into the buffer pointed to by s. Reading stops after
 * an EOF or a newline. If a newline is read, it is stored into the buffer.
 * A terminating null byte ('\0') is stored after the last character in the
 * buffer.
 *
 * fgets() return s on success, and NULL on error or when end of file
 * occurs while no characters have been read.
 */

#include <stdio.h>
#include <string.h>

#define ERR_TEST

//char *fgets(char *s, int size, FILE *stream);
int main()
{
    char *res = NULL;
#ifdef ERR_TEST
    char dst[8] = "";
    // if input 'hhhhaaaa9'
    // *** stack smashing detected ***: ./a.out terminated
    // Aborted
    res = fgets(dst, 16, stdin);
    if (res) {
        printf("recv - %s\n", dst);
    }
#else
    char dst[1000];

    memset(dst, 0, sizeof(dst));
    while ((res = fgets(dst, 10, stdin))) {
        printf("dst is %s, size is %d\n", dst, strlen(dst));
    }
#endif
    return 0;
}
