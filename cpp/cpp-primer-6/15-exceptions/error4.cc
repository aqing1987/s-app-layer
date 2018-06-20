// using exception classes
// One important advantage of this is that you can use different
// exception types to distinguish among different functions and
// situations that produce exceptions. Also an object can carry
// information with it, and you can use this information to help
// identify the conditions that caused the exception be thrown.
#include <iostream>
#include <cmath> // or math.h, unix users may need -lm flag
#include "exc_mean.h"

double hmean(double a, double b) {
  if (a == -b)
    throw bad_hmean(a, b);

  return 2.0 * a * b / (a + b);
}

double gmean(double a, double b) {
  if (a < 0 || b < 0)
    throw bad_gmean(a, b);

  return std::sqrt(a * b);
}

int main(int argc, char *argv[]) {
  using std::cout;
  using std::cin;
  using std::endl;

  double x, y, z;
  cout << "Enter two numbers: ";
  while (cin >> x >> y) {
    try {
      z = hmean(x, y);
      cout << "Harmonic mean of " << x << " and " << y << " is "
           << z << endl;
      cout << "Geometric mean of " << x << " and " << y << " is "
           << gmean(x, y) << endl;
    } catch (bad_hmean& bh) {
      bh.mesg();
      cout << "Try again.\n";
      continue;
    } catch (bad_gmean& bg) {
      cout << bg.mesg();
      cout << "Values used: " << bg.v1 << ", "
           << bg.v2 << endl;
      cout << "Sorry, you don't get to play any more.\n";
      break;
    } // end of catch block

    cout << "Enter next set of numbers <q to quit>: ";
  }

  cout << "Bye!\n";
  return 0;
}
