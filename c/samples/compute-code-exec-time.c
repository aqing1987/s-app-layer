#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
  struct timeval start_st, end_st;
  unsigned long total_tm = 0;

  // int gettimeofday(struct timeval *tv, struct timezone *tz);
  gettimeofday(&start_st, NULL);

  sleep(2);

  gettimeofday(&end_st, NULL);

  total_tm = 1000000 * (end_st.tv_sec - start_st.tv_sec) +
      (end_st.tv_usec - start_st.tv_usec);

  printf("exec time = %ld (us)\n", total_tm);

  return 0;
}
