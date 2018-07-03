// the sum of 100's 0.1 is not 10
#include <stdio.h>

int main(int argc, char *argv[]) {
  float sum = 0.0;

  for (int i = 0; i < 100; i++)
    sum += 0.1;

  printf("%f\n", sum);
  return 0;
}
