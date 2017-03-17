// vegnews.cpp -- using new and delete with classes
// compile with stringbad.cpp
#include <iostream>

#include "stringbad.h"

using std::cout;

void callme1(StringBad &); // pass by reference
void callme2(StringBad); // pass by value

int main(int argc, char *argv[])
{
  using std::endl;

  // places the object declarations within an inner block because
  // the destructor is called when execution exits the block in which
  // an object is defined.
  {
    cout << "Starting an inner block.\n";
    StringBad headline1("Celery Stalks at Midnight");
    StringBad headline2("Lettuce Prey");
    StringBad sports("Spinach Leaves Bow1 for Dollars");

    cout << "headline1: " << headline1 << endl;
    cout << "headline2: " << headline2 << endl;
    cout << "sports: " << sports << endl;

    callme1(headline1);
    cout << "headline1: " << headline1 << endl;

    // First, passing headline2 as a function argument somehow causes the
    // destructor to be called. Second, although passing by value is supposed
    // to protect the original argument from change, the function messes up
    // the original string beyond recognition, and some nonstandard characters
    // get displayed. (the exact text displayed will depend on what happens to
    // sitting in memory.)
    callme2(headline2);
    cout << "headline2: " << headline2 << endl;

    cout << "Initialize one object to another:\n";
    StringBad sailor = sports;
    cout << "sailor: " << sailor << endl;

    cout << "Assign one object to another:\n";
    StringBad knot;
    knot = headline1;
    cout << "knot: " << knot << endl;

    cout << "Exiting the block.\n";
  }
  return 0;
}

void callme1(StringBad & rsb) {
  cout << "String passed by reference:\n";
  cout << "   \"" << rsb << "\"\n";
}

void callme2(StringBad sb) {
  cout << "String passed by value:\n";
  cout << "   \"" << sb << "\"\n";
}
