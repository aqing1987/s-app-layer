// string1.cpp -- String class methods
#include <cstring> // string.h for some

#include "string1.h" // include <iostream>

using std::cin;
using std::cout;

// === initializing static class member

int String::num_strings = 0;

// static method
int String::HowMany() {
  return num_strings;
}

// === class methods
// construct String from C string
String::String(const char * s) {
  // set size
  len = std::strlen(s);
  // allot storage
  str = new char[len + 1];
  // initialize pointer
  std::strcpy(str, s);
  // set object count
  num_strings++;
}

// default constructor
String::String() {
  len = 4;
  str = new char[1];
  // default string
  str[0] = '\0';
  num_strings++;
}

// copy constructor
String::String(const String & st) {
  // handle static member update
  num_strings++;
  // same length
  len = st.len;
  // allot storage
  str = new char[len + 1];
  // copy string to new location
  std::strcpy(str, st.str);
}

// necessary destructor
String::~String() {
  --num_strings;
  delete [] str;
}

// === overloaded operator methods

// assign a String to a String
String & String::operator=(const String & st) {
  if (this == &st)
    return *this;

  delete [] str;
  len = st.len;
  str = new char[len + 1];
  std::strcpy(str, st.str);
  return *this;
}

// assign a C string to a String
String & String::operator=(const char * s) {
  delete [] str;
  len = std::strlen(s);
  str = new char[len+1];
  std::strcpy(str, s);
  return *this;
}

// read-write char access for non-const String
char & String::operator[](int i) {
  return str[i];
}

// read-only char access for const String
const char & String::operator[](int i) const {
  return str[i];
}

// === overloaded operator friends
bool operator<(const String &st1, const String &st2) {
  return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String &st1, const String &st2) {
  return (st2 < st1);
}

bool operator==(const String &st1, const String &st2) {
  return (std::strcmp(st1.str, st2.str) == 0);
}

// simple String output
ostream & operator<<(ostream &os, const String &st) {
  os << st.str;
  return os;
}

// quick and dirty String input
// It assumes an input line of String::CINLIM or fewer characters and discards
// any characters beyond that limit.
istream & operator>>(istream &is, String &st) {
  char temp[String::CINLIM];
  is.get(temp, String::CINLIM);
  if (is) {
    st = temp;
  }

  while (is && is.get() != '\n')
    continue;

  return is;
}