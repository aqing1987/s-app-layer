#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    // uid_t getuid(void);
    // getuid() returns the real user ID of the calling process.
    // gid_t getgid(void);
    // getgid() returns the real group ID of the calling process.
    printf("uid = %d, gid = %d\n", getuid(), getgid());
    return 0;
}
