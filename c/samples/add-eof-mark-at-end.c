#include <stdio.h>

static unsigned char eof_mark[4] = {0xde, 0xad, 0xc0, 0xde};
static unsigned char *pad = eof_mark;
static int pad_len = sizeof(eof_mark);

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return -1;
    }

    FILE *fp = NULL;
    ssize_t out_len;
    const char *name = argv[1];

    fp = fopen(name, "a");
    if (fp == NULL) {
        printf("Unable to open %s", name);
        return -1;
    }

      /* write out the JFFS end-of-filesystem marker */
    out_len = fwrite(pad, 1, pad_len, fp);
    if (out_len != pad_len) {
        printf("Unable to write to %s (padlen = %d, outlen=%d)\n",
               name, (int)pad_len, (int)out_len);
        fclose(fp);
        return -1;
    }

    fclose(fp);

    return 0;
}
