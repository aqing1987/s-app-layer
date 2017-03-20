// stringbad.cpp -- StringBad class methods
// Warning:
// Whenever you use new in a constructor to allocate memory, you should use delete
// in the corresponding destructor to free that memory. If you use new[] (with brackets),
// then you should use delete[] (with brackets).
// c++ automatically provides the following member function:
// 1. A default constructor if you define no constructors
// 2. A default destructor if you don't define one
// 3. A copy constructor if you don't define one
// 4. An assignment operator if you don't define one
// 5. An address operator if you don't define one
// For example, if you assign one object to another, the program provides
// a definition for the assignment operator.
// It turns out that the implicit copy constructor and the imlicit assignment
// operator cause the StringBad class problems.
//
// Caution:
// If a class contains members that are pointers initialized by new, you should
// define a copy constructor that copies the pointed-to data instead of copying
// the pointers themselves. This is termed deep copying. The alternative form
// of copying(memberwise, or shallow, copying) just copies pointer values.
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

// copy constructor
// make a deep copy
// That is, rather than just copy the address of the string, the copy
// constructor should duplicate the string and assign the address of the
// duplicate to the str memeber. That way, each object gets its own
// string rather than referring to another object's string. And each call
// of the destructor frees a different string rather than making duplicate
// attempts at freeing the same string.
StringBad::StringBad(const StringBad & st) {
  num_strings++; // handle static
  len = st.len; // same length
  str = new char[len + 1]; // allot space
  std::strcpy(str, st.str); // copy string to new location

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

// the solution for the problems created by an inappropirate default
// assignment operator is to provide your own assignment operator definition,
// one that makes a deep copy.
// Assignment does not create a new object, so you don't have to adjust the
// value of the static data member num_strings.
StringBad & StringBad::operator=(const StringBad & st) {
  // checks for self-assignment
  if (this == &st) { // object assigned to itself
    return *this; // all done
  }

  // free old string
  // the reason for this is that shortly thereafter str will be assigned
  // the address of a new string. If you don't first apply the delete
  // operator, the previous string will remain in memory.
  delete [] str;
  len = st.len;
  str = new char [len + 1]; // get space for new string
  std::strcpy(str, st.str); // copy the string

  return *this; // return reference to invoking object
}

std::ostream & operator<<(std::ostream & os, const StringBad & st) {
  os << st.str;
  return os;
}
