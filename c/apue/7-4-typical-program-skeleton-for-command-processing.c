#include <stdio.h>

#define MAX_LINE     512
#define TOK_ADD      5

char *g_tok_ptr;

static void cmd_add(void)
{
    int token;

    token = get_token();

    // rest of processing for this command
}

static void do_line(char *ptr)
{
    int cmd;

    g_tok_ptr = ptr;
    while ((cmd = get_token()) > 0) {
        switch (cmd) {
        case TOK_ADD:
            cmd_add();
            break;

        default:
            break;
        }
    }
}

int main(int argc, char *argv[])
{
    char line[MAX_LINE];

    while (fgets(line, MAX_LINE, stdin) != NULL) {
        do_line(line);
    }

    return 0;
}
