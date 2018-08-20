/*
 * Very simple, given a number, find its opposite.
 * Examples:
 * 1: -1
 * 14: -14
 * -34: 34
 *
 * But can you do it in 1 line of code and without any conditionals?
 * */
#include <iostream>

int opposite(int number) {
  return -number;
}

int main() {
  std::cout << opposite(1) << std::endl;
  return 0;
}

