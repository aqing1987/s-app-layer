/**
 * @brief
 * list item style, they are stored in .list
 *    00124B000294A221_20000103_085448.mp4 300 946860888
 *
 * cp from tf .list to udisk .list
 */
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    char cmd[256];
    char *item="00124B000294A221_20000103_085448.mp4";
    char *srcfile="./srclist";
    char *dstfile="./dstlist";

    sprintf(cmd,
            "val=$(grep '%s' %s | head -n 1); \
            if [ ! -z \"$val\" ]; then echo $val >> %s ;fi",
            item, srcfile, dstfile);
    system(cmd);

    return 0;
}

