#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define TEXT_SIZE  512

struct msgbuf {
    long mtype;
    int  status;
    char mtext[TEXT_SIZE];
};

int main(int argc, char **argv)
{
    int msqid;
    struct msgbuf buf;
    int sendlen;
    int key;
    int flag;

    // convert  a pathname and a project identifier to a System V IPC key
    // key_t ftok(const char *pathname, int proj_id);
    // must  refer to an existing, accessible file
    key = ftok("msg.tmp", 0x01);
    if (key < 0) {
        perror("ftok");
        return -1;
    }

    // msgget - get a System V message queue identifier
    // int msgget(key_t key, int msgflg);
    msqid = msgget(key, 0600|IPC_CREAT);
    if (msqid < 0) {
        perror("create message queue error");
        return -1;
    }

    buf.mtype = 1;
    buf.status = 9;
    strcpy(buf.mtext, "happy new year!");
    sendlen = sizeof(struct msgbuf) - sizeof(long);

    //int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg);
    flag = msgsnd(msqid, &buf, sendlen, 0);
    if (flag < 0) {
        perror("send message error");
        return -1 ;
    }

    system("ipcs -q");

    return 0 ;
}
