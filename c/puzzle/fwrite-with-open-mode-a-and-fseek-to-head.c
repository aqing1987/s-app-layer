/**
 * @brief
 *    `man fopen'
 *    Opening a file in append mode (a as the first character of mode)
 *    causes all subsequent write operations to this stream to occur at
 *    end-of-file, as if preceded the call:
 *       fseek(stream, 0, SEEK_END);
 *
 *    Use "r+b" mode and fallback to "w+b" if it fails.
 *    The "a+b" mode, allows you to read and append.
 *    The "r+b" allows random read and write.
 * */

#include <stdio.h>

#define FNAME "./tt.o"

void read_binary_file_content(char *fname, unsigned int len)
{
    if (fname == NULL || len == 0) {
        printf("invalid param\n");
        return;
    }

    FILE *fp = fopen(fname, "rb");
    unsigned int i = 0;
    char rbyte = 0;

    printf("0x: ");
    for (i = 0; i < len; i++) {
        fread(&rbyte, 1, 1, fp);
        printf("%x ", rbyte);
    }
    printf("\n");
    fclose(fp);
}

int main(int argc, char *argv[])
{
    char wbuf[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
    char wbuf2[4] = {0x0C, 0x0C, 0x0C, 0x0C};

    FILE *fp = fopen(FNAME, "wb");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    if (fwrite(wbuf, 1, 8, fp) != 8) {
        perror("fwrite");
    }
    fclose(fp);

    // check result
    read_binary_file_content(FNAME, 8);

    // fwrite with open mode 'a' test now
    fp = fopen(FNAME, "ab");
    // move to the head
    fseek(fp, 0, SEEK_SET);

    printf("current positon = %ld\n", ftell(fp));

    fwrite(wbuf2, 1, 4, fp);
    fclose(fp);

    // check result
    // Note: fseek is no use for fopen with "ab"
    // still write to the end of the file
    read_binary_file_content(FNAME, 12);

    return 0;
}
