// usestock0.cpp -- the client program
// compile with stock00.cpp
// The Client/Server Model
// OOP programmers often discuss program design in terms of a client/server
// model. In this conceptualization, the client is a program that uses the
// class. The class declaration, including the class methods, constitute the
// server, which is a resource that is available to the programs that need it.
// The client uses the server through the publicly defined interface only.
// This means that the client's only responsibility, and, by extension, the
// client's programmer's only responsibility, is to know that interface.
// Any changes the server designer makes to the class design should be to
// details of implementation, not to the interface. This allows programmers
// to improve the client and the server independently of each other, without
// changes in the server having unforseen repercussions on the client's behavior
#include <iostream>
#include "stock00.h"

int main(int argc, char *argv[])
{
  Stock fluffy_the_cat;

  fluffy_the_cat.acquire("NanoSmart", 20, 12.50);
  fluffy_the_cat.show();
  fluffy_the_cat.buy(15, 18.125);
  fluffy_the_cat.show();
  fluffy_the_cat.sell(400, 20.00);
  fluffy_the_cat.show();
  fluffy_the_cat.buy(300000, 40.125);
  fluffy_the_cat.show();
  fluffy_the_cat.sell(300000, 0.125);
  fluffy_the_cat.show();

  return 0;
}
