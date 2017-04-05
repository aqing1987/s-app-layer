// studentc.h -- defining a Student class using private inheritance
// Copyright 2017 Kevin All rights reserved.
#ifndef STUDENTCI_H_
#define STUDENTCI_H_

#include <iostream>
#include <string>
#include <valarray>

class Student : private std::string, private std::valarray<double> {
  typedef std::valarray<double> ArrayDb;

 public:
  // What happens if you don't use the initialization list syntax?
  // As with inherited components, C++ requires that all member objects be
  // constructed before the rest of an object is constructed. So if you omit
  // the initialization list, C++ uses the default constructors defined for
  // member objects' classes.
Student() : std::string("Null Student"), ArrayDb() {}
  // use explicit turns off implicit conversion
  explicit Student(const std::string& s) : std::string(s), ArrayDb() {}
  explicit Student(int n) : std::string("Null"), ArrayDb(n) {}
  Student(const std::string& s, int n) : std::string(s), ArrayDb(n) {}
  Student(const std::string& s, const ArrayDb& a)
      : std::string(s), ArrayDb(a) {}
  Student(const char* str, const double* pd, int n)
      : std::string(str), ArrayDb(pd, n) {}
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
  std::ostream& arr_out(std::ostream& os) const;
};

#endif  // STUDENTCI_H_
