// usetime2.cpp -- using the third draft of the Time class
// compile usetime2.cpp and mytime2.cpp together
#include <iostream>
#include "mytime2.h"

int main(int argc, char *argv[])
{
  using std::cout;
  using std::endl;

  Time weeding(4, 35);
  Time waxing(2, 47);
  Time total;
  Time diff;
  Time adjusted;

  cout << "weeding time = ";
  weeding.Show();
  cout << endl;

  cout << "waxing time = ";
  waxing.Show();
  cout << endl;

  cout << "total work time = ";
  total = weeding + waxing; // use operator+()
  total.Show();
  cout << endl;

  cout << "weeding time - waxing time = ";
  diff = weeding - waxing; // use operator-()
  diff.Show();
  cout << endl;

  cout << "adjusted work time = ";
  adjusted = total * 1.5; // use operator*()
  adjusted.Show();
  cout << endl;

  return 0;
}
