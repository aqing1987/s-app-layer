/*
 * Given an array of integers, return a new array with each value doubled.
 * For example:
 * [1, 2, 3] --> [2, 4, 6]
 *
 * For the beginner, try to use the map method - it comes in very handy quite
 * a lot so is a good one to know.
 * */

#include <iostream>
#include <vector>

// better solution
std::vector<int> maps2(const std::vector<int> & values) {
  std::vector<int> result;

  for (auto a : values) {
    result.push_back(a*2);
  }

  return result;
}

std::vector<int> maps(const std::vector<int> & values) {

  std::vector<int> out;

  for (unsigned int i = 0; i < values.size(); ++i)
    out.push_back(values[i]*2);

  return out;
}

int main() {
  std::vector<int> a;
  a.push_back(1);
  a.push_back(2);
  a.push_back(3);

  std::vector<int> b;
  b = maps2(a);
  for (std::vector<int>::iterator it = b.begin(); it != b.end(); ++it)
    std::cout << *it << " ";
  std::cout << "\n";

  return 0;
}