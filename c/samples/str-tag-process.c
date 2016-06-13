#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void wifi_wpa_cli_msg_cb(const char *msg, size_t len)
{
    const char *pos = NULL;

    pos = msg;
    if (*pos == '<') {
        printf("msg: %s, len = %d\n", msg, (int)len);
            // locate character in string
            // char *strchr(const char *s, int c);
            // return a pointer to the matched character or NULL if
            // the character is not found.  The terminating null byte is
            // considered part of the string, so that if c is specified
            // as '\0', these functions return a pointer to the terminator.
        pos = strchr(pos, '>');
    }
    else {
        printf("invalid msg!\n");
        exit(1);
    }
    printf("string after tag: %s\n", pos+1);
}

int main()
{
    char *str = "<wifi> hello, world!";

    wifi_wpa_cli_msg_cb(str, strlen(str)+1);

    return 0;
}
