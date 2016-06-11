#include <stdio.h>

struct CURLMsg {
    int msg;           /* what this message means */
    char *easy_handle; /* the handle it concerns */
    union {
        void *whatever;/* message-specific data */
        int result;    /* return code for transfer */
    } data;
};

int main(int argc, char *argv[])
{
    struct CURLMsg m;

    m.data.result = 1;
    printf("result = %d\n", m.data.result);

    return 0;
}
