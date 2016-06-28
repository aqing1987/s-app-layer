#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <limits.h>

#ifdef OPEN_MAX
static long openmax = OPEN_MAX;
#else
static long openmax = 0;
#endif

/**
 * if OPEN_MAX is indeterminate, we're not guaranteed that
 * this is adequate
 */
#define OPEN_MAX_GUESS    256

long open_max(void)
{
    if (openmax == 0) {
        errno = 0;
        // long sysconf(int name);
        // POSIX allows an application to test at compile or run time whether cer‐
        // tain options are supported, or what the value  is  of  certain  config‐
        // urable constants or limits.
        // _SC_OPEN_MAX
        // The  maximum number of files that a process can have open at any
        // time.  Must not be less than _POSIX_OPEN_MAX (20)
        if ((openmax = sysconf(_SC_OPEN_MAX)) < 0) {
            if (errno == 0) {
                openmax = OPEN_MAX_GUESS;
            }
            else {
                perror("sysconf");
            }
        }
    }

    return openmax;
}

int main(int argc, char *argv[])
{
    printf("max file descriptors number is %ld\n", open_max());

    return 0;
}
