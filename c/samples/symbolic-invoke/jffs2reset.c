#include <stdio.h>
#include <string.h>

static int jffs2_reset(int argc, char **argv)
{
    printf("jffs2_reset invoked.\n");

    return 0;
}

static int jffs2_mark(int argc, char **argv)
{
    printf("jffs2_mark invoked.\n");

    return 0;
}

int main(int argc, char **argv)
{
    if (strstr(argv[0], "jffs2mark")) {
        return jffs2_mark(argc, argv);
    }

    return jffs2_reset(argc, argv);
}
