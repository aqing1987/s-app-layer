/**
 * Your task is to return the sum of Triangular Numbers
 * p-to-and-including the nth Triangular Number.
 *
 * Triangular Number: "any of the series of numbers (1, 3, 6, 10, 15,
 * etc.) obtained by continued summation of the natural numbers 1, 2,
 * 3, 4, 5, etc."
 * [01]
 * 02 [03]
 * 04 05 [06]
 * 07 08 09 [10]
 * 11 12 13 14 [15]
 * 16 17 18 19 20 [21]
 *
 * e.g. If 4 is given: 1 + 3 + 6 + 10 = 20.
 * Triangular Numbers cannot be negative so return 0 if a negative
 * number is given.
 */

#include <stdio.h>

// === my solution
int triangular_num(int nth) {
  if (nth <= 0)
    return 0;

  if (nth == 1)
    return 1;
  else
    return nth + triangular_num(nth-1);
}

int sum(int nth) {
  if (nth <= 0)
    return 0;
  
  int i = 0, sum = 0;

  for (i = 1; i <= nth; i++) {
    sum += triangular_num(i);
  }
  return sum;
}

// === clever 1
int sumTriangularNumbers(int n) {
  int sum = 0, sumTot = 0;
  int i;
  for (i = 1; i <= n; i++) {
    sum += i; //sum is increased everytime by i which is increased everytime by 1
    sumTot += sum; //sum is everytime added to sumTot which accumulate every cycle's result
  }

  return sumTot;
}

// === clever 2
int sumTriangularNumbers1(int n) {
  if (n <= 0) {
    return 0;
  }
  return n*(n+1)*(n+2)/6;
}

int main(int argc, char *argv[]) {
  int n;

  printf("input nth\n");
  scanf("%d", &n);
  printf("out: %d\n", sum(n));
  return 0;
}
