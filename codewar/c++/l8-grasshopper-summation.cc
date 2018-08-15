/*
 * Summation
 * Write a program that finds the summation of every number between 1 and num.
 * The number will always be a positive integer greater than 0.
 *
 * For example:
 * summation(8) -> 36
 * 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8
 * */

#include <iostream>

// better solution
int summation2(int num) {
  return num*(num+1) / 2;
}

int summation(int num) {
  int sum = 0;
  for (int i = 1; i <= num; i++) {
    sum += i;
  }

  return sum;
}

int main() {
  std::cout << summation2(8) << std::endl;
}