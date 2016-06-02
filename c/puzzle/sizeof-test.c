#include <stdio.h>

typedef struct {
    int running;
    int cur_wr_index;
    int cur_rd_index;
    int pending;
    unsigned int pktSize;
    unsigned int bufferCnt;
    unsigned char buf[5][1400];
} shared_audio_dat;


int main(int argc, char *argv[])
{
    shared_audio_dat ss;

    printf("sizeof(shared_audio_dat) = %lu\n", sizeof(shared_audio_dat));
    printf("sizeof(ss) = %lu\n", sizeof(ss));
    printf("sizeof(ss->buf) = %lu\n", sizeof(ss.buf));
    printf("sizeof(pending-1) = %lu\n", sizeof(ss.pending));

#if 1
      // only struct object can operate it's member
    printf("sizeof(pending-2) = %lu\n", sizeof(shared_audio_dat.pending));
#endif

    return 0;
}
