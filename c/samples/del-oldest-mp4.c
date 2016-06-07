#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char cmd[256];
    const char *mount_dir="./";

    // del oldest mp4 and it's list item
    sprintf(cmd,
            "del_file=$(ls -rt %s/*.mp4 | head -n 1); \
            rm $del_file; sync; \
            sed -i /^`basename $del_file`/d %s/.list",
            mount_dir, mount_dir);
    system(cmd);

    return 0;
}

