#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

int main(int argc, char *argv[])
{
    double total_ms = 0;

    struct timeval start_st, end_st;

    // int gettimeofday(struct timeval *tv, struct timezone *tz);
    gettimeofday(&start_st, NULL);

    sleep(2);

    gettimeofday(&end_st, NULL);

    total_ms = (end_st.tv_sec*1000 + end_st.tv_usec/1000) -
        (start_st.tv_sec*1000 - start_st.tv_usec/1000);

    printf("exec time = %f (ms)\n", total_ms);

    return 0;
}
