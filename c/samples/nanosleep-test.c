#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

// If nanosleep interrupted by a signal handler  or  encounters
// an error, then it returns  -1, with errno set to indicate the error.
void sleep_new(long long msec)
{
    struct timespec ts;
    int err = 0;

    ts.tv_sec = (msec / 1000);
    ts.tv_nsec = (msec % 1000) * 1000 * 1000;

    do {
        if (err < 0) {
            printf("errno = %d\n", errno);
        }

        err = nanosleep(&ts, &ts);
    } while (err < 0 && errno == EINTR);

    printf("end of %s\n", __func__);
}

void alarm_handler(int arg)
{
    printf("%s, called.\n", __func__);
}

int main(int argc, char *argv[])
{
    // signal() sets the disposition of the signal signum to handler
    signal(SIGALRM, alarm_handler);

    alarm(2);
    sleep_new(5000);

    return 0;
}
