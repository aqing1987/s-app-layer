#include <stdio.h>

#define REC_ERROR_BASE            0x1000

#define REC_EC_OK                 0
#define REC_EC_FAIL               (-REC_ERROR_BASE)
#define REC_EC_PARA_WRONG         -(REC_ERROR_BASE + 1)
#define REC_EC_MALLOC_FAIL        -(REC_ERROR_BASE + 2)
#define REC_EC_SOCKET_INIT_FAIL   -(REC_ERROR_BASE + 3)
#define REC_EC_NOT_SUPPORT        -(REC_ERROR_BASE + 4)


int main(int argc, char *argv[])
{
    int opt = 0;

    opt = REC_EC_NOT_SUPPORT;

    switch (opt) {
    case REC_EC_NOT_SUPPORT:
        printf("opt = %d\n", REC_EC_NOT_SUPPORT);
        break;

    case REC_EC_FAIL:
        printf("opt = %d\n", REC_EC_FAIL);
        break;
    }

    return 0;
}
