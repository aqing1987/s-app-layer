// usestock1.cpp -- using the Stock class
// compile with stock10.cpp
// If you can set object values either through initialization or by
// assignment, choose initialization. It is usually more efficient.
#include <iostream>
#include "stock10.h"

int main(int argc, char *argv[])
{
  {
    using std::cout;
    cout << "Using constructors to create new objects\n";
    Stock stock1("NanoSmart", 12, 20.0); // syntax 1
    stock1.show();

    Stock stock2 = Stock("Boffo Objects", 2, 2.0); // syntax 2
    stock2.show();

    cout << "Assigning stock1 to stock2:\n";
    // you can assign one object to another of the same type
    // When you assign one object to another of the same class, by
    // default C++ copies the contents of each data member of the souce
    // object to the corresponding data member of the target object.
    stock2 = stock1;
    cout << "Listing stock1 and stock2:\n";
    stock1.show();
    stock2.show();

    cout << "Using a constructor to reset an object\n";
    // instead of initializing stock1, this statement assigns new values
    // to the object. It does so by having the constructor create a new
    // temporary object and then copying the contents of the new object to
    // stock1. Then the program disposes of the temporary object, invoking
    // the destructor as it does so.
    stock1 = Stock("Nifty Foods", 10, 50.0); // temp object
    cout << "Revised stock1:\n";
    stock1.show();
    cout << "Done\n";
  }

  return 0;
}
