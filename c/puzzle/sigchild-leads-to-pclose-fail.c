#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

int main(int argc, char *argv[]) {

  // when SIGCHLD ignored, pclose will failed with: No child processes
  signal(SIGCHLD, SIG_IGN);
  
  FILE* f = NULL;
  f = popen("top -bn1", "r");
  if (f == NULL) {
    printf("popen: %s\n", strerror(errno));
    return -1;
  }

  int ret = 0;
  ret = pclose(f);
  if (ret < 0) {
    printf("pclose: %s\n", strerror(errno));
    return -1;
  }

  
  return 0;
}
