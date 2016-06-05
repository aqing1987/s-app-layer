#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void my_signal_func(int signum)
{
    static int cnt = 0;
    printf("signal = %d, %d times\n", signum, ++cnt);
}

int main(int argc, char *argv[])
{
    // kill -USR1 PID for test
    signal(SIGUSR1, my_signal_func);

    while (1) {
        sleep(1000);
    }

    return 0;
}
