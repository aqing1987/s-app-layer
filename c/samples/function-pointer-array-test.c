#include <stdio.h>
#include <stdlib.h>

enum rtsp_method {
    RTSP_METHOD_DESCRIBE,
    RTSP_METHOD_SETUP,
    RTSP_METHOD_PLAY,
    RTSP_METHOD_NUM,
    RTSP_METHOD_NONE = RTSP_METHOD_NUM,
};

struct rtsp_sess{
    int a;
    int b;
} rtsp_sess;

static int send_method_play(struct rtsp_sess *sessp)
{
    printf("play\n");
    return 0;
}

static int send_method_setup(struct rtsp_sess *sessp)
{
    printf("setup\n");
    return 0;
}

static int send_method_describe(struct rtsp_sess *sessp)
{
    printf("describe\n");
    return 0;
}

int main(int argc, char *argv[])
{
    struct rtsp_sess *sessp = NULL;

    sessp = malloc(sizeof(struct rtsp_sess));

    static int (*send_method[])(struct rtsp_sess *) = {
        [RTSP_METHOD_DESCRIBE]      = send_method_describe,
        [RTSP_METHOD_SETUP]         = send_method_setup,
        [RTSP_METHOD_PLAY]          = send_method_play,
    };


    send_method[RTSP_METHOD_SETUP](sessp);
    send_method[RTSP_METHOD_DESCRIBE](sessp);
    send_method[RTSP_METHOD_PLAY](sessp);
    return 0;
}