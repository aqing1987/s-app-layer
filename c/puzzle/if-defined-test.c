#include <stdio.h>

#define AUDIO_TYPE_PCMA
#define AUDIO_TYPE_PCM
//#define AUDIO_TYPE_AAC

int main(int argc, char *argv[])
{
#if defined(AUDIO_TYPE_AAC)
    printf("audio-aac\n");
#elif defined(AUDIO_TYPE_PCM)
    printf("audio-pcm\n");
#elif defined(AUDIO_TYPE_PCMA)
    printf("audio-pcma\n");
#endif

    return 0;
}
