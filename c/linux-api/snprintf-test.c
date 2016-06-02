/**
 * int sprintf(char *str, const char *format, ...);
 * int snprintf(char *str, size_t size, const char *format, ...);
 *
 * sprintf(),  snprintf(), vsprintf() and vsnprintf() write the output
 * to the character string str.
 *
 * The  functions  snprintf()  and  vsnprintf() write at most size bytes
 * (including the terminating null byte ('\0')) to str.
 */

#include <stdio.h>

int main()
{
    int block = 1024;
    char str_block[4];

    sprintf(str_block, "%03X", block);
    printf("str_block1 = %s\n", str_block);

      // snprintf will put '\0' to the last char array element
    snprintf(str_block, sizeof(str_block), "abcdefg");
    printf("str_block2 = %s\n", str_block);

    return 0;
}
