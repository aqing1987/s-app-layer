#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *mp4_fd;

    // open in current dir
    mp4_fd = fopen("./a.tmp", "wb");

    // write content
    char buf[4] = "\x00\x01\x02\x03";
    fwrite(buf, 1, 4, mp4_fd);

    // close file
    fclose(mp4_fd);

    // move file
    system("mv ./a.tmp /tmp/;sync");

    // change file pointer
    mp4_fd = fopen("/tmp/a.tmp", "ab");

    // write another content
    char nbuf[4] = "\x08\x09\x08\x09";
    fwrite(nbuf, 1, 4, mp4_fd);

    // close
    fclose(mp4_fd);

    printf("job done.\n");

    return 0;
}
