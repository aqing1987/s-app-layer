// unwinding the stack
// An extremely important aspect of exceptions: As the program unwinds
// the stack to reach where an exception is caught, it frees automatic
// storage class variables on the stack. If a variable happens to be
// a class object, then the destructor for that object is called.
#include <iostream>
#include <cmath>
#include <string>

#include "exc_mean.h"

class Demo {
 public:
  Demo(const std::string& str) {
    word = str;
    std::cout << "demo " << word << " created\n";
  }

  ~Demo() {
    std::cout << "demo " << word << " destroyed\n";
  }

  void show() const {
    std::cout << "demo " << word << " lives!\n";
  }

 private:
  std::string word;
};

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

double means(double a, double b) {
  double am, hm, gm;

  Demo d2("found in means()");
  am = (a + b) / 2.0; // arithmetic mean
  try {
    hm = hmean(a, b);
    gm = gmean(a, b);
  } catch (bad_hmean& bh) {
    bh.mesg();
    std::cout << "Caught in means() \n";
    throw; // rethrows the exception
  }

  d2.show();

  return (am + hm + gm) / 3.0;
}

int main(int argc, char *argv[]) {
  using std::cout;
  using std::cin;
  using std::endl;

  double x, y, z;
  {
    Demo d1("found in block in main()");
    cout << "Enter two numbers: ";
    while (cin >> x >> y) {
      try {
        z = means(x, y);
        cout << "The mean mean of " << x << " and " << y
             << " is " << z << endl;
        cout << "Enter next pair: ";
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
      }
    }

    d1.show();
  }

  cout << "Bye!\n";
  cin.get();
  cin.get();
  return 0;
}
