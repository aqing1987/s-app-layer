// stonewt.cpp -- Stonewt methods
#include <iostream>

#include "stonewt.h"

using std::cout;

// construct  Stonewt object from double value
// template for double-to-Stonewt conversion
// In C++, any constructor that takes a single argument acts as a
// blueprint for converting a value of that argument type to the class type.
// Thus the following constructor serves as instructions for converting
// a type double value to a type Stonewt value.
// That is, you can write code like the following:
// Stonewt myCat;
// myCat = 19.6; // use Stonewt(double) to convert 19.6 to Stonewt
// The program uses the Stonewt(double) constructor to construct a temporary
// Stonewt object, using 19.6 as the initialization value. Then memberwise assignment
// copies the contents of the temporary object into myCat.
// This process is termed an implicit conversion because it happens automatically,
// without the need of an explicit type cast.
// C++ added a new keyword, explicit, to turn off the automatic aspect. That is, you
// can declare the constructor this way:
// explicit Stonewt(double lbs); // no implicit conversions allowed
Stonewt::Stonewt(double lbs) {
  stone = int (lbs) / Lbs_per_stn; // integer division
  pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
  pounds = lbs;
}

// construct Stonewt object from stone, double values
// Only a constructor that can be used with just one argument works as a conversion
// function. The following constructor has two arguments, so it cannot be used to
// convert types.
// However, it would act as a guide to int conversion if it provided a default value
// for the second parameter:
// Stonewt::Stonewt(int stn, double lbs = 0); // int-to-Stonewt conversion
Stonewt::Stonewt(int stn, double lbs) {
  stone = stn;
  pds_left = lbs;
  pounds = stn * Lbs_per_stn + lbs;
}

// default constructor, wt = 0
Stonewt::Stonewt() {
  stone = pounds = pds_left = 0;
}

// destructor
Stonewt::~Stonewt() {
}

// show weight in stones
void Stonewt::show_stn() const {
  cout << stone << " stone, " << pds_left << " pounds\n";
}

// show weight in pounds
void Stonewt::show_lbs() const {
  cout << pounds << " pounds.\n";
}