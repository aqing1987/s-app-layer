#include <stdio.h>

typedef enum {
    REC_MODE_NONE = 0,
    REC_MODE_ONCE,
    REC_MODE_ALWAYS,
} REC_MODE_E;

const char *str_of_rec_mode(REC_MODE_E mode)
{
    switch (mode) {
    case REC_MODE_NONE:
        return "rec mode none";
    case REC_MODE_ONCE:
        return "rec mode once";
    case REC_MODE_ALWAYS:
        return "rec mode always";
    }

    return "rec mode err";
}

int main(int argc, char *argv[])
{
    printf("%s\n", str_of_rec_mode(REC_MODE_ALWAYS));

    return 0;
}
