// stringbad.cpp -- StringBad class methods
// Warning:
// Whenever you use new in a constructor to allocate memory, you should use delete
// in the corresponding destructor to free that memory. If you use new[] (with brackets),
// then you should use delete[] (with brackets).
#include <cstring> // string.h for some

#include "stringbad.h"

using std::cout;

// initializing static class member
// Note that you cannot initialize a static member variable inside the
// class declaration. That's because the static class member is stored
// separately rather than as part of an object.
// Note that the initialization statement give the type and uses the scope
// operator, but it doesn't use the static keyword.
// This initialization goes in the methods file, not in the class declaration
// file. That's because the class declaration is in a header file, and a program
// may include a header file in several other files. That would result in
// multiple copies of the initialization statement, which is an error.
// However, if the static member is a const integral type or an enumeration type,
// it can be initialized in the class declaration itself.
int StringBad::num_strings = 0;

// class methods

// construct StringBad from C string
StringBad::StringBad(const char * s) {
  // strlen() returns the length of a string, not counting the terminating null character.
  len = std::strlen(s); // set size
  str = new char[len + 1]; // allocate storage
  std::strcpy(str, s); // initialize pointer
  num_strings++; // set object count
  cout << num_strings << ": \"" << str
       << "\" object created. \n"; // for your information
}

// default constructor
StringBad::StringBad() {
  len = 4;
  str = new char[4];
  std::strcpy(str, "C++"); // default string
  num_strings++;
  cout << num_strings << ": \"" << str
       << "\" object created. \n"; // for your information
}

// necessary destructor
StringBad::~StringBad() {
  cout << "\"" << str << "\" object deleted, "; // FYI
  --num_strings;
  cout << num_strings << " left\n"; // FYI

  // by placing the delete statement in the destructor, you ensure
  // that the memory that a constructor allocates with new is freed
  // when the object expires.
  delete [] str; // required
}

std::ostream & operator<<(std::ostream & os, const StringBad & st) {
  os << st.str;
  return os;
}