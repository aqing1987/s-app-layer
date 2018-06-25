// Using a Stack of Pointers Incorrectly
// Copyright 2018 Neil All rights reserved.

#include <iostream>
#include <string>
#include <cctype>

#include "stacktp.h"

using std::cin;
using std::cout;

// The idea is to use a char pointer instead of a string object to
// receive the keyboard input. This approach fails immediately
// because merely creating a pointer doesn't create space to hold
// the input string.
int main(int argc, char *argv[]) {
  Stack<char *> st; // create a stack for pointers-to-char
  char ch;
  char* po;
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