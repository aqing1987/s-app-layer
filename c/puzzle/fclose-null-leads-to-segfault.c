#include <stdio.h>

int main(int argc, char *argv[]) {
  // The  behaviour  of  fclose() is undefined if the stream parameter
  // is an illegal pointer, or is a descriptor already passed to a
  // previous  invocation of fclose().
  fclose(NULL);
  return 0;
}
