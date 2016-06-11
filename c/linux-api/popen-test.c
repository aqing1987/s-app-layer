/**
 * The popen() function opens a process by creating a pipe, forking, and
 * invoking the shell.
 * FILE *popen(const char *command, const char *type);
 * the 'type' argument may specify  only  reading  or  writing,  not  both
 * The 'command' argument is a pointer to a null-terminated string containing
 * a shell command line. This command is passed to /bin/sh using the -c  flag;
 */
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *fd = NULL;
    char rtsp_en_val[4]; // used to store rtsp enable item value.
    const char *get_rtsp_enable_str = "getprop ipc rtsp_enable";

    // FILE *popen(const char *command, const char *type);
    memset(rtsp_en_val, 0, sizeof(rtsp_en_val));
    fd = popen(get_rtsp_enable_str, "r");
    if (fd == NULL) {
        fprintf(stderr, "%s, popen fail\n", __func__);
        return -1;
    }

    if ( !fgets(rtsp_en_val, sizeof(rtsp_en_val)-1, fd)) {
        fprintf(stderr, "%s, fgets fail\n", __func__);
        pclose(fd);
        return -1;
    }
    pclose(fd);

    // if disabled, return.
    printf("get %s from stream.\n", rtsp_en_val);
    if (strstr(rtsp_en_val, "0")) {
        return 0;
    }

    return 1;
}