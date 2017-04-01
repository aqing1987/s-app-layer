// studentc.h -- defining a Student class using containment
// Copyright 2017 Kevin All rights reserved.
#ifndef STUDENTC_H_
#define STUDENTC_H_

#include <iostream>
#include <string>
#include <valarray>

class Student {
  typedef std::valarray<double> ArrayDb;

 public:
  // What happens if you don't use the initialization list syntax?
  // As with inherited components, C++ requires that all member objects be
  // constructed before the rest of an object is constructed. So if you omit
  // the initialization list, C++ uses the default constructors defined for
  // member objects' classes.
  Student() : name_("Null Student"), scores_() {}
  // use explicit turns off implicit conversion
  explicit Student(const std::string& s) : name_(s), scores_() {}
  explicit Student(int n) : name_("Null"), scores_(n) {}
  Student(const std::string& s, int n) : name_(s), scores_(n) {}
  Student(const std::string& s, const ArrayDb& a) : name_(s), scores_(a) {}
  Student(const char* str, const double* pd, int n)
    : name_(str), scores_(pd, n) {}
  ~Student() {}

  double Average() const;
  const std::string& Name() const;
  double& operator[](int i);
  double operator[](int i) const;

  // friends input
  friend std::istream& operator>>(std::istream& is, Student& stu);  // 1 word
  friend std::istream& getline(std::istream& is, Student& stu);  // 1 line
  // friends output
  friend std::ostream& operator<<(std::ostream& os, const Student& stu);

 private:
  // When you have a member initializer list that initializes more than one
  // item, the items are initialized in the order in which they were declared
  // not in the order in which they appear in the initializer list.
  std::string name_;  // contained object
  ArrayDb scores_;  // contained object

  std::ostream& arr_out(std::ostream& os) const;
};

#endif  // STUDENTC_H_
