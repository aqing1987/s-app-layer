// randwalk.cpp -- using the Vector class
// compile with the vect.cpp file
#include <iostream>
#include <cstdlib> // rand(), srand() prototypes
#include <ctime> // time() prototype
#include <fstream>

#include "vect.h"

int main(int argc, char *argv[])
{
  using namespace std;
  // use using declaration brings Vector into scope
  // importing the class name also makes the Vector methods availabe,
  // without the need for any further using declarations.
  using VECTOR::Vector;

  double direction;
  Vector step;
  Vector result(0.0, 0.0);
  unsigned long steps = 0;
  double target;
  double dstep;

  ofstream fout;
  fout.open("thewalk.txt");

  // set a different seed each time you run the program, making
  // the random output appear even more random
  srand(time(0)); // seed random-number generator
  cout << "Enter target distance (q to quit): ";
  while (cin >> target) {
    cout << "Enter step length: ";
    if (!(cin >> dstep))
      break;

    while (result.magval() < target) {
      direction = rand() % 360;
      step.reset(dstep, direction, Vector::POL);
      result = result + step;
      steps++;
      fout << result << endl;
    }

    cout << "After " << steps << " steps, the subject "
        "has the following location:\n";
    cout << result << endl;
    result.polar_mode();
    cout << " or\n" << result << endl;
    cout << "Average outward distance per step = "
         << result.magval() / steps << endl;

    steps = 0;
    result.reset(0.0, 0.0);
    cout << "Enter target distance (q to quit): ";
  }

  fout.close();

  cout << "Bye!\n";
  cin.clear();
  while (cin.get() != '\n') {
    continue;
  }

  return 0;
}
