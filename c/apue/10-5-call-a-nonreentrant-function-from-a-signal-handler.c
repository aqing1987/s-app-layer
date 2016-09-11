/**
 * When this program was run, the results were random.
 * As shown by this example, if we call a nonreentrant function from
 * a signal handler, the results are unpredictable.
 */
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <pwd.h>

static void my_alarm(int signo)
{
    struct passwd *rootptr;

    printf("in signal handler\n");
    if ((rootptr = getpwnam("root")) == NULL) {
        perror("getpwnam(root)");
    }

    alarm(1);
}

int main(int argc, char *argv[])
{
    struct passwd *ptr;

    signal(SIGALRM, my_alarm);
    alarm(1);

    for ( ; ; ) {
        if ((ptr = getpwnam("sshd")) == NULL) {
            perror("getpwnam(sshd)");
        }

        if (strcmp(ptr->pw_name, "sshd") != 0) {
            printf("retrun value corrupted!, pw_name = %s\n",
                   ptr->pw_name);
        }
    }

    return 0;
}
