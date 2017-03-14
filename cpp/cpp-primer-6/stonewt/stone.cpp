// stone.cpp -- user-defined conversions
// compile with stonewt.cpp

#include <iostream>
#include "stonewt.h"

using std::cout;

void display(const Stonewt & st, int n);

int main(int argc, char *argv[]) {
  // a syntax for initializing a class object when using a
  // constructor with one argument. This is equivalent to the
  // other two forms:
  // standard syntax forms for initializing class objects
  // Stonewt incognito(275);
  // Stonewt incognito = Stonewt(275);
  Stonewt incognito = 275; // uses constructor to initialize
  Stonewt wolfe(285.7); // same as Stonewt wolfe = 285.7
  Stonewt taft(21, 8);

  cout << "The celebrity weighed ";
  incognito.show_stn();
  cout << "The detective weighted ";
  wolfe.show_stn();
  cout << "the President weighed ";
  taft.show_lbs();

  incognito = 276.8; // uses constructor for conversion
  taft = 325; // same as taft = Stonewt(325);
  cout << "After dinner, the celebrity weighed ";
  incognito.show_stn();
  cout << "After dinner, the President weighed ";
  taft.show_lbs();

  display(taft, 2);
  cout << "The wrestler weighed even more.\n";
  display(422, 2); // convert 422 to double, then to Stonewt
  cout << "No stone left unearned\n";

  return 0;
}

void display(const Stonewt & st, int n) {
  for (int i = 0; i < n; i++) {
    cout << "Wow! ";
    st.show_stn();
  }
}