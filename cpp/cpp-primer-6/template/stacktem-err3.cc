// Using a Stack of Pointers Incorrectly - ver3
// Copyright 2018 Neil All rights reserved.

#include <iostream>
#include <string>
#include <cctype>

#include "stacktp.h"

using std::cin;
using std::cout;

// po is a variable and hence compatible with the code for pop().
// Here, however, you come up against the most fundamental problem.
// There is only one po variable, and it always points to the same
// memory location. Every push operation puts exactly the same
// address onto the stack. So when you pop the stack, you always
// get the same address back, and it always refers to the last string
// read into the memory.
int main(int argc, char *argv[]) {
  Stack<char *> st; // create a stack for pointers-to-char
  char ch;
  char* po = new char[40];
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
