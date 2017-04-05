// studentc.cc -- Student class using private inheritance
// Copyright 2017 Kevin All rights reserved.

#include "./studentci.h"

using std::ostream;
using std::endl;
using std::istream;
using std::string;

// public methods

// inheritance lets you use the class name and the scope-resolution operator
// to invoke base-class methods.
double Student::Average() const {
  if (ArrayDb::size() > 0)
    return ArrayDb::sum() / ArrayDb::size();
  else
    return 0;
}

// student is derived from string, it's possible to type cast a Student
// object to a string object; the result is the inherited string object.
// To avoid invoking constructors to create new objects, you use the type
// cast to create a reference.
const string& Student::Name() const {
  return (const string&) *this;
}

double& Student::operator[](int i) {
  return ArrayDb::operator[](i);  // use valarray<double>::operator[]()
}

double Student::operator[](int i) const {
  return ArrayDb::operator[](i);
}

// private methods

ostream& Student::arr_out(ostream& os) const {
  int i;
  int lim = ArrayDb::size();

  if (lim > 0) {
    for (i = 0; i < lim; i++) {
      os << ArrayDb::operator[](i) << " ";
      if (i % 5 == 4)
        os << endl;
    }
    if (i % 5 != 0)
      os << endl;
  } else {
    os << "empty array ";
  }

  return os;
}

// Accessing Base-Class Friends

// use an explicit type cast to the base class to invoke the correct functions.
// use string version of operator>>()
istream& operator>>(istream& is, Student& stu) {
  is >> (string&) stu;
  return is;
}

istream& getline(istream& is, Student& stu) {
  getline(is, (string&) stu);
  return is;
}

// use string version of operator<<()
ostream& operator<<(ostream& os, const Student& stu) {
  os << "Scores for " << (const string&) stu << ":\n";
  stu.arr_out(os);  // use private method for scores

  return os;
}
