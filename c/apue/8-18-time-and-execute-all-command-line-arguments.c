/**
 * usage:
 *   ./a.out "sleep 5" "date"
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/times.h>
#include <sys/types.h>
#include <sys/wait.h>

#ifdef WCOREDUMP
unsigned char coredump_enable = 1;
#endif

static void pr_exit(int status)
{
    if (WIFEXITED(status)) {
        printf("normal termination, exit status = %d\n",
               WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
        if (coredump_enable) {
            printf("abnormal termination, signal number = %d%s\n",
                   WTERMSIG(status),
                   WCOREDUMP(status) ? " (core file generated)" : "");
        } else {
            printf("abnormal termination, signal number = %d\n",
                   WTERMSIG(status));
        }
    } else if (WIFSTOPPED(status)) {
        printf("child stopped, signal number = %d\n", WSTOPSIG(status));
    }
}

static void pr_times(clock_t real, struct tms *tmsstart, struct tms *tmsend)
{
    static long clktck = 0;

    if (clktck == 0) {
        if ((clktck = sysconf(_SC_CLK_TCK)) < 0) {
            perror("sysconf");
        }
    }

    printf("real: %7.2f\n", real/(double)clktck);
    printf("user: %7.2f\n",
           (tmsend->tms_utime - tmsstart->tms_utime)/(double)clktck);
    printf("sys: %7.2f\n",
           (tmsend->tms_stime - tmsstart->tms_stime)/(double)clktck);
    printf("child user: %7.2f\n",
           (tmsend->tms_cutime - tmsstart->tms_cutime)/(double)clktck);
    printf("child sys: %7.2f\n",
           (tmsend->tms_cstime - tmsstart->tms_cstime)/(double)clktck);
}

static void do_cmd(const char *cmd)
{
    struct tms tmsstart, tmsend;
    clock_t start, end;
    int status;

    printf("\ncommand: %s\n", cmd);
    if ((start = times(&tmsstart)) < 0) {
        perror("times 1");
    }

    if ((status = system(cmd)) < 0) {
        perror("systeme");
    }

    if ((end = times(&tmsend)) < 0) {
        perror("times 2");
    }

    pr_times(end-start, &tmsstart, &tmsend);
    pr_exit(status);
}

int main(int argc, char *argv[])
{
    int i;

    setbuf(stdout, NULL);

    for (i = 1; i < argc; i++) {
        do_cmd(argv[i]); // once for each command-line arg
    }

    return 0;
}
