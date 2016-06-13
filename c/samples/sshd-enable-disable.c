#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CMD_LEN 128

static void disable_ssh()
{
    char cmd[CMD_LEN];

    snprintf(cmd, sizeof(cmd)-1, "killall \"sshd\"");
    system(cmd);
    
    printf("================================\n");
    snprintf(cmd, sizeof(cmd)-1, "ps -ef | grep \"sshd\"");
    system(cmd);
}

static void enable_ssh()
{
    char cmd[CMD_LEN];

    snprintf(cmd, sizeof(cmd)-1, "/usr/sbin/sshd &");
    system(cmd);
    
    printf("================================\n");
    snprintf(cmd, sizeof(cmd)-1, "ps -ef | grep \"sshd\"");
    system(cmd);
}


int main(int argc, char *argv[])
{
    int enable = -1;
        
    if (argc != 2) {
        printf("Usage: %s [0|1]\n\t 0 for disable, 1 for enable\n", argv[0]);
        return -1;
    }

    enable = atoi(argv[1]);
    if (enable != 0 && enable != 1) {
        printf("invalid parameter. argv[1] = %d\n", enable);
        return -1;
    }

    if (enable == 1)
        enable_ssh();
    else if (enable == 0)
        disable_ssh();
    
    return 0;
}

