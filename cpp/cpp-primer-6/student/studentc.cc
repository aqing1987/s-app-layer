// studentc.cc -- Student class using containment
// Copyright 2017 Kevin All rights reserved.

#include "./studentc.h"

using std::ostream;
using std::endl;
using std::istream;
using std::string;

// public methods

// using a interface for a contained object
// In short, the Student object invokes a Student method, and the Studnet
// method uses the contained valarray object to invoke valarray methods.
double Student::Average() const {
  if (scores_.size() > 0)
    return scores_.sum() / scores_.size();
  else
    return 0;
}

const string& Student::Name() const {
  return name_;
}

double& Student::operator[](int i) {
  return scores_[i];  // use valarray<double>::operator[]()
}

double Student::operator[](int i) const {
  return scores_[i];
}

// private methods

ostream& Student::arr_out(ostream& os) const {
  int i;
  int lim = scores_.size();

  if (lim > 0) {
    for (i = 0; i < lim; i++) {
      os << scores_[i] << " ";
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

// friends

// use string version of operator>>()
istream& operator>>(istream& is, Student& stu) {
  is >> stu.name_;
  return is;
}

istream& getline(istream& is, Student& stu) {
  getline(is, stu.name_);
  return is;
}

// use string version of operator<<()
ostream& operator<<(ostream& os, const Student& stu) {
  os << "Scores for " << stu.name_ << ":\n";
  stu.arr_out(os);  // use private method for scores

  return os;
}
