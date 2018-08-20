/*
 * Introduction
 * The first century spans from the year 1 up to and including the year 100,
 * The second - from the year 101 up to and including the year 200, etc.
 *
 * Task:
 * Given a year, return the century it is in.
 *
 * Input , Output Examples ::
 * centuryFromYear(1705)  returns (18)
 * centuryFromYear(1900)  returns (19)
 * centuryFromYear(1601)  returns (17)
 * centuryFromYear(2000)  returns (20)
 * */

#include <iostream>

// better1
constexpr int centuryFromYear2(int year) {
  return (year + 99) / 100;
}

int centuryFromYear(int year) {
  int y = year / 100;
  int r = year % 100;

  return (r > 0 ? y+1: y);
}

int main() {

  std::cout << centuryFromYear(1705) << std::endl;
  std::cout << centuryFromYear(1900) << std::endl;

  return 0;
}