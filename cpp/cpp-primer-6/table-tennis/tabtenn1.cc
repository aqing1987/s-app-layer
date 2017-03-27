// tabtenn1.cc -- simple derived-class methods
#include <iostream>

#include "tabtenn1.h"

TableTennisPlayer::TableTennisPlayer(const string &fn, const string &ln,
                                     bool ht) : firstname(fn),
                                                lastname(ln),
                                                hasTable(ht) {}

void TableTennisPlayer::Name() const {
  std::cout << lastname << ", " << firstname;
}

// RatedPlayer methods

// If you don't supply a base-class constructor in a member initializer list,
// the program uses the default base-class constructor. The member initializer
// list can be used only in constructor.
// When creating an object of a derived class, a program first calls the
// base-class constructor and then calls the derived-class constructor. The
// base-class constructor is responsible for initializing the inherited data
// members. The derived-class constructor is responsible for initializing any
// added data members. A derived-class constructor always calls a base-class
// constructor. You can use the initializer list syntax to indicate which
// base-class constructor to use. Otherwise, the default base-class constructor
// is used. When an object of a derived class expires, the program first calls
// the derived-class destructor and then calls the base-class destructor.
RatedPlayer::RatedPlayer(unsigned int r, const string &fn, const string &ln,
                         bool ht) : TableTennisPlayer(fn, ln, ht) {
  rating = r;
}

RatedPlayer::RatedPlayer(unsigned int r,
                         const TableTennisPlayer &tp) : TableTennisPlayer(tp),
                                                        rating(r) {}
