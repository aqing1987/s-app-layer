/*
 * Task
 * Given three integers a ,b ,c, return the largest number obtained after
 * inserting the following operators and brackets: +, *, ().
 *
 * Consider an Example :
 * With the numbers are 1, 2 and 3 , here are some ways of placing signs and
 * brackets:
 * 1 * (2 + 3) = 5
 * 1 * 2 * 3 = 6
 * 1 + 2 * 3 = 7
 * (1 + 2) * 3 = 9
 * So the maximum value that you can obtain is 9.
 *
 * Notes
 * The numbers are always positive.
 * The numbers are in the range (1  ≤  a, b, c  ≤  10).
 * You can use the same operation more than once.
 * _It's not necessary to place all the signs and brackets.
 * Repetition in numbers may occur .
 * You cannot swap the operands. For instance, in the given example you cannot
 * get expression (1 + 3) * 2 = 8.
 * */
#include <iostream>

// better one, compile with -std=c++11
#include <algorithm>

unsigned short expressionsMatter2(unsigned short a, unsigned short b, unsigned short c) {
  return std::max({a + b + c, a * (b + c), (a + b) * c, a * b * c});
}

unsigned short int expressionsMatter(unsigned short int a, unsigned short int b, unsigned short int c)
{
  int max = 0;

  int c1;
  c1 = a+b+c;
  max = max > c1 ? max : c1;

  int c2;
  c2 = a*b+c;
  max = max > c2 ? max : c2;

  int c3;
  c3 = a+b*c;
  max = max > c3 ? max : c3;

  int c4;
  c4 = (a+b)*c;
  max = max > c4 ? max : c4;

  int c5;
  c5 = a*(b+c);
  max = max > c5 ? max : c5;

  int c6;
  c6 = a*b*c;
  max = max > c6 ? max : c6;

  return max;
}

int main() {
  std::cout << expressionsMatter2((3),(5),(7)) << std::endl;
  return 0;
}