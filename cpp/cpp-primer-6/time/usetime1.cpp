// usetime1.cpp -- using the second draft of the Time class
// compile usetime1.cpp and mytime1.cpp together
// the name of the operator+() function allows it to be invoked by
// using either function notation or operator notation.
#include <iostream>
#include "mytime1.h"

int main(int argc, char *argv[])
{
  using std::cout;
  using std::endl;

  Time planning;
  Time coding(2, 40);
  Time fixing(5, 55);
  Time total;

  cout << "planning time = ";
  planning.Show();
  cout << endl;

  cout << "coding time = ";
  coding.Show();
  cout << endl;

  cout << "fixing time = ";
  fixing.Show();
  cout << endl;

  // operator notation
  total = coding + fixing;
  cout << "coding + fixing = ";
  total.Show();
  cout << endl;

  Time morefixing(3, 28);
  cout << "more fixing time = ";
  morefixing.Show();
  cout << endl;

  // function notation
  total = morefixing.operator+(total);
  cout << "morefixing.operator+(total) = ";
  total.Show();
  cout << endl;

  return 0;
}
