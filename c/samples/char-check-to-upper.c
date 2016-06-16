#include <stdio.h>
#include <string.h>
#include <ctype.h>

static int str_check2upper(char *buf, int len)
{
    int i = 0;

    for (i = 0; i < len; i++) {
        if (buf[i] >= '0' && buf[i] <= '9')
            continue;
        else if (buf[i] >= 'A' && buf[i] <= 'Z')
            continue;
        else if (buf[i] >= 'a' && buf[i] <= 'z')
            buf[i] = buf[i] + 'A' - 'a';
        else
            return -1;
    }

    return 0;
}

static void str_2_upper(char *buf, int len)
{
    int i = 0;

    for (i = 0; i < len; i++) {
        buf[i] = toupper(buf[i]);
    }
}

int main(int argc, char **argv)
{
    char buf[4];
    int i = 0;

    if (argc != 2) {
        printf("Usage: %s string\n", argv[0]);
        return -2;
    }

    memset(buf, 0, sizeof(buf));
    memcpy(buf, argv[1], sizeof(buf)-1);

    if (str_check2upper(buf, strlen(buf)) < 0)
        printf("invalid string\n");
    else {
        for (i = 0; i < strlen(buf); i++)
            printf("buf[%d] = %c\n", i, buf[i]);
    }

    // strupr api
    char small[5] = "abc";
    str_2_upper(small, strlen(small));
    printf("not small = %s\n", small);

    return 0;
}
