#include <stdio.h>
#include <unistd.h>

//i	son/pa	ppid	pid	 fpid
//0	parent	4525	5530	5531
//1	parent	4525	5530	5532
//0	child	5530	5531	   0
//1	child	5530	5532	   0
//1	parent	1736	5531	5533
//1	child	5531	5533	   0

//                           - p5530 (parent)
//       - p5530 (parent) - |
//                           - p5532 (child)
// p5530 |
//                          - p5531 (parent)
//       - p5531 (child) - |
//                          - p5533 (child)
//
// if fork N times
// printf times = 2*(1+2+4+...+2^(N-1))
// child process numbers = 1+2+4+...+2^(N-1)
int main()
{
    pid_t fpid = 0;
    int i = 0;

    printf("i\tson/pa\tppid\tpid\t fpid\n");
    // pid_t fork(void);
    // fork()  creates  a new process by duplicating the calling process.
    // The new process, referred to as the child, is an exact duplicate of
    // the calling  process,  referred  to as the parent
    for (i = 0; i < 2; i++) {
        fpid = fork();
        if (fpid < 0) {
            perror("fork 1");
            return -1;
        }
        else if (fpid == 0) {
            printf("%d\tchild\t%4d\t%4d\t%4d\n", i, getppid(), getpid(), fpid);
        }
        else {
            printf("%d\tparent\t%4d\t%4d\t%4d\n", i, getppid(), getpid(), fpid);
        }
    }

    return 0;
}
