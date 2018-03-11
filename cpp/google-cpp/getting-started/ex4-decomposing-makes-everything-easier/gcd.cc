// gcd.cc: x
// Description: An implementation of Euclid's algorithm for computing gcd
// (greatest common divisor). Fundamental idea of Euclid's algorithm (one of
// the oldest known algorithms) for finding the greatest common divisor of two
// integers:
// gcd(a, 0) = a
// gcd(a, b) = gcd(b, a % b)
// For example, gcd(6, 4) = 2; gcd(12, 18) = 6

#include <iostream>
using namespace std;

// A non-recursive version of Euclid's algorithm
int gcd(int a, int b) {
  int tmp;
  while (b != 0) {
    tmp = a % b;
    a = b;
    b = tmp;
  }
  return a;
}

int main(int argc, char *argv[argc]) {
  int x, y;
  cout << "Enter two integers: ";
  if (!(cin >> x >> y)) {
    cout << "Please enter only integers" << endl;
  } else {
    cout << "gcd(" << x << ", "<< y << ") = " << gcd(x, y) << endl;
  }
  return 0;
}
