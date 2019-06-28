#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int buffsize = 1600;
  if (argc == 2) {
    buffsize = atoi(argv[1]);
  }

  printf("send-buffer size: %d\n", buffsize);
  unsigned char *pbuf = (unsigned char*)malloc(buffsize);
  if (!pbuf) {
    printf("malloc error\n");
    return -1;
  }

  for (int i = 0; i < buffsize; i++)
    pbuf[i] = i % 254;
  
  int sock_send;
  if ((sock_send = (socket(AF_INET, SOCK_DGRAM, 0))) < 0) {
    printf("socket err\n");
    free(pbuf);
    return -1;
  }

  int so_broadcast = 1;
  struct sockaddr_in recv_addr;
  setsockopt(sock_send, SOL_SOCKET, SO_BROADCAST, &so_broadcast, sizeof(so_broadcast));
  recv_addr.sin_family = AF_INET;
  recv_addr.sin_addr.s_addr = htonl(INADDR_BROADCAST);
  recv_addr.sin_port = htons(51518);

  int val;
  while (1) {
    val = sendto(sock_send, pbuf, buffsize, MSG_DONTWAIT, (struct sockaddr *)&recv_addr, sizeof(recv_addr));
    if (val < 0)
      printf("sendto error: %s\n", strerror(errno));
    else
      printf("send bytes: %d\n", val);
    
    sleep(1);
  }
  
  close(sock_send);
  free(pbuf);
  return 0;
}
