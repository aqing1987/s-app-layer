#include <stdio.h>
#include <string.h>


#define XX X2

#if XX == X1
# define CLEANMARKER "\x19\x85\x20\x03"
#else
# define CLEANMARKER "\x85\x19\x03\x20"
#endif

int main(int argc, char *argv[])
{
    unsigned char buf[4] = "";

    memcpy(buf, CLEANMARKER, 4);

    int i = 0;
    for (i = 0; i < 4; i++)
        printf("%x ", buf[i]);
    printf("\n");
    
    return 0;
}
