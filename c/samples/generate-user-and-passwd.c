// compile with -lcrypt
#define _XOPEN_SOURCE

#include <stdio.h>
#include <unistd.h>

int main(int argc, char*argv[]) {
  if(argc != 3){
    printf("usage: %s username plainpwd\n", argv[0]);
    return -1;
  }

  printf("username: %s\npasswd: %s\n", argv[1], argv[2]);
  printf("generated pwd: %s\n", crypt(argv[1], argv[2]));

  return 0;
}