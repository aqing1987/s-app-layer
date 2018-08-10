/*
 * Task: Complete the SquareSum method so that it squares each number passed
 *       into it and then sums the results together.
 *
 * e.g.
 * const int values[] = { 1, 2, 2 };
const size_t count = sizeof(values)/sizeof(values[0]);

square_sum(values, count); // should return 9
 *
 * */
#include <stdio.h>
#include <math.h>


int SquareSum(const int *values, size_t count) {
  int sum = 0;

  for (int i = 0; i < count; i++) {
    sum += values[i] * values[i];
  }

  return sum;
}

int main() {
  const int values[] = {1, 2, 2};
  const size_t count = sizeof(values) / sizeof(values[0]);

  int ret = 0;
  ret = SquareSum(values, count);
  printf("%d\n", ret);

  return 0;
}