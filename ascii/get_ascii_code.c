#include <stdio.h>

int main(int argc, char* argv[]) {

  unsigned int tmp;
  unsigned char as;

  printf("Enter the number: ");
  scanf("%i", &tmp);

  as = (int)tmp;  //output ASCII
  printf("ASCII: %c", as);
  printf("\n 10cc: %u", tmp);
  printf("\n 16cc: %x", tmp);
  printf("h\n");

  return 0;
}