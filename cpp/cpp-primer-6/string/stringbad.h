// stringbad.h -- flawed string class definition
// Why can the class StringBad?
// This is to remind you that StringBad is an example under development.
// It's the first stage of developing a class by using dynamic memory allocation,
// and it does the obvious things correctly. It doesn't really do bad things, but
// the design omits doing some additional good things that are necessary but not
// at all obvious.
#ifndef STRINGBAD_H_
#define STRINGBAD_H_

#include <iostream>

class StringBad {
 private:
  // 1. it uses a pointer-to-char instead of a char array to represent name.
  //    This means that the class declaration does not allocate storage space
  //    for the string itself. Instead, it uses new in the constructors to allocate
  //    space for the string.
  char * str; // pointer to string
  int len; // length of string
  // 2. a static class member has a special property: A program creates only one
  //    copy of a static class variable, regardless of the number of objects created.
  //    that is, a static member is shared among all objects of that class. This is
  //    convenient for data that should be private to a class but that should have the
  //    same value for all class objects.
  static int num_strings; // number of objects created

 public:
  StringBad(const char * s); // constructor
  StringBad(const StringBad & st); // copy constructor
  StringBad(); // default constructor
  ~StringBad(); // destructor
  StringBad & operator=(const StringBad &); // overload assignment operator

  // friend function
  friend std::ostream & operator<<(std::ostream & os, const StringBad & st);
};

#endif