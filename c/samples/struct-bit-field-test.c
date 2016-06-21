#include <stdio.h>

typedef struct {
    unsigned char version;
    unsigned int flags : 24; // only low 24 bits enabled
} fullbox_t;

int main(int argc, char *argv[])
{
    fullbox_t box1, box2;

    box1.version = 1;
    box1.flags = 0x100001;

    printf("box1.version = %d, box1.flags = 0x%x\n",
           box1.version, box1.flags);

    box2.version = 2;
    box2.flags = 0x10101010;
    printf("box2.version = %d, box2.flags = 0x%x\n",
           box2.version, box2.flags);

    return 0;
}
