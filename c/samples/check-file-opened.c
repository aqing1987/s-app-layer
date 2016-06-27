#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

static int check_shell_cmd_response(const char *cmd, char *ret, unsigned int ret_size)
{
    if (cmd == NULL || ret == NULL || ret_size == 0) {
        printf("invalid pointer(%s)", __func__);
        return -1;
    }

    FILE *fd = popen(cmd, "r");
    if (fd == NULL) {
        printf("popen err(%s)", __func__);
        return -1;
    }

    // char *fgets(char *s, int size, FILE *stream);
    // reads in at most one less than size characters from stream
    // and stores them into the buffer pointed to by s.
    // Reading stops after an EOF or a newline.
    fgets(ret, ret_size, fd);
    pclose(fd);

    int rlen = 0;
    rlen = strlen(ret);
    if (rlen > 0 && ret[rlen-1] == '\n') {
        ret[rlen-1] = '\0';
    }

    return 0;
}

/**
 * @brief
 *    check if file opend by some process
 * @return
 *    -1 - error
 *     0 - file not opened
 *     1 - file opened
 * */
static int file_open_check(const char *fname)
{
    char cmd[128];
    char cmd_res_buf[128];
    int file_opened = 0;

    if (fname == NULL || strlen(fname) == 0) {
        return -1;
    }

    memset(cmd_res_buf, 0, sizeof(cmd_res_buf));
    sprintf(cmd, "lsof %s | grep -v COMMAND | awk -F ' ' '{print $2}'", fname);

    if (check_shell_cmd_response(cmd, cmd_res_buf, sizeof(cmd_res_buf)-1) < 0) {
        return -1;
    }

    if (strlen(cmd_res_buf) > 0)
    file_opened = 1;

    return file_opened;
}


int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s name\n", argv[0]);
        return -1;
    }

    int ret = 0;

    FILE *fp = NULL;
    fp = fopen(argv[1], "r");
    if (!fp) {
        perror("fopen");
        return -1;
    }

    ret = file_open_check(argv[1]);
    if (ret == 1) {
        printf("file has been opened by others.\n");
    }
    else {
        printf("file not opened yet.\n");
    }

    fclose(fp);

    return 0;
}
