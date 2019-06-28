#include <stdio.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

void Dump(unsigned char* buf, int size) {
  for (int i = 0; i < size; i++)
    printf("%02X", buf[i]);
  printf("\n\n\n");
}

unsigned char buffer[80000] = {0};

int main() {
  fd_set rd;
  int recv_socket = 0;

  recv_socket = socket(AF_INET, SOCK_DGRAM, 0);

  int so_reuse = 1, flags;
  flags = fcntl(recv_socket, F_GETFL, 0);
  fcntl(recv_socket, F_SETFL, flags | O_NONBLOCK);

  struct sockaddr_in server_sockaddr;
  server_sockaddr.sin_family = AF_INET;
  server_sockaddr.sin_port = htons(51518);
  server_sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  setsockopt(recv_socket, SOL_SOCKET, SO_REUSEADDR, &so_reuse, sizeof(so_reuse));

  if (bind(recv_socket, (struct sockaddr *)&server_sockaddr, sizeof(server_sockaddr)) == -1) {
    printf("bind error: %s\n", strerror(errno));
    return -1;
  }

  struct timeval tv;
  int ret = 0;
  ssize_t rt = 0;
  struct sockaddr_in addr;
  int addr_len = sizeof(struct sockaddr_in);

  while (1) {
    FD_ZERO(&rd);
    FD_SET(recv_socket, &rd);

    memset(buffer, 0, sizeof(buffer));
    tv.tv_sec = 2;
    tv.tv_usec = 0;

    ret = select(recv_socket + 1, &rd, NULL, NULL, &tv);
    if (ret > 0) {
      if (FD_ISSET(recv_socket, &rd)) {
        rt = recvfrom(recv_socket, buffer, sizeof(buffer), MSG_DONTWAIT, (struct sockaddr *)&addr, (void *)&addr_len);
        if (rt > 0) {
          Dump(buffer, rt);
        } else if (rt == 0) {
          printf("no message available!\n");
        } else if (rt < 0) {
          printf("error: %s\n", strerror(errno));
        }
      }
    }
  }

  return 0;
}
