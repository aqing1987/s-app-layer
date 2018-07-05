#include <stdio.h>
#include <string.h>
#include <stdint.h>

int main(int argc, char *argv[]) {

  float data;
  uint32_t buff = 0;
  char s[36];

  printf("input float number: ");
  scanf("%f", &data);

  memset(s, 0, sizeof(s));
  memcpy(&buff, &data, 4);

  for (int i = 33; i >= 0; i--) {
    if (i == 1 || i == 10) {
      s[i] = '-';
    } else {
      if (buff % 2 == 0)
        s[i] = '0';
      else
        s[i] = '1';

      buff >>= 1;
    }
  }

  s[34] = '\0';
  printf("%s\n", s);
  
  return 0;
}
