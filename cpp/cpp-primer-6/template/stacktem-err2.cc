// Using a Stack of Pointers Incorrectly - ver2
// Copyright 2018 Neil All rights reserved.

#include <iostream>
#include <string>
#include <cctype>

#include "stacktp.h"

using std::cin;
using std::cout;

// compile err
// error: invalid initialization of non-const reference of
// type ‘char*&’ from an rvalue of type ‘char*’

// for pop
// bool Stack<type>::pop<Type & item>
// First, the reference variable item has to refer to an lvalue of
// some sort, not to an array name. Second, the code assumes that you
// can assign to item. Even if item could refer to an array, you
// can't assign to an array name.
int main(int argc, char *argv[]) {
  Stack<char *> st; // create a stack for pointers-to-char
  char ch;
  char po[40]; // allocates space for an input string
  cout << "please enter A to add a purchase order,\n"
       << "P to process a PO, or Q to qut.\n";
  while (cin >> ch && std::toupper(ch) != 'Q') {
    while (cin.get() != '\n')
      continue;
    if (!std::isalpha(ch)) {
      cout << '\a';
      continue;
    }
    switch (ch) {
      case 'A':
      case 'a':
        cout << "Enter a PO number to add: ";
        cin >> po;
        if (st.isfull())
          cout << "stack already full\n";
        else
          st.push(po);
        break;
      case 'P':
      case 'p':
        if (st.isempty()) {
          cout << "stack already empty\n";
        } else {
          st.pop(po);
          cout << "PO #" << po << " popped\n";
        }
        break;
    }

    cout << "please enter A to add a purchase order,\n"
       << "P to process a PO, or Q to qut.\n";
  }
  cout << "Bye\n";

  return 0;
}
