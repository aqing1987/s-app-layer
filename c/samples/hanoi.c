#include <stdio.h>

void hanoi(int n, char x, char y, char z) {
  if (n == 0) {
    // do nothing
  } else {
    // move n-1 from x to z
    hanoi(n-1, x, z, y);

    // move the biggest of n from x to y
    printf("%c -> %c, ", x, y);

    // move n-1 from z to y
    hanoi(n-1, z, y, x);
  }
}

int main() {
  hanoi(6, 'A', 'B', 'C');
  return -1;
}
