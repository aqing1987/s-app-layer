// stonewt1.cpp -- Stonewt class methods + conversion functions
#include <iostream>

#include "stonewt1.h"

using std::cout;

// construct Stonewt object from double value
Stonewt::Stonewt(double lbs) {
  stone = int (lbs) / Lbs_per_stn; // integer division
  pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
  pounds = lbs;
}

// construct Stonewt object from stone, double values
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

// conversion functions
// int conversion definition rounds to the nearest integer
// rather than truncating.
Stonewt::operator int() const {
  return int (pounds + 0.5);
}

Stonewt::operator double() const {
  return pounds;
}