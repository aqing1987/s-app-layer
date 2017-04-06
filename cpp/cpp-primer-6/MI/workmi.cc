// worktest.cc -- test MI worker class hierarchy
// compile with workermi.cc
// Copyright 2017 Kevin All rights reserved.
#include <iostream>
#include <cstring>

#include "workermi.h"

const int kSize = 5;

int main(int argc, char *argv[]) {
  using std::cin;
  using std::cout;
  using std::endl;
  using std::strchr;

  Worker* lolas[kSize];

  int ct;
  for (ct = 0; ct < kSize; ct++) {
    char choice;
    cout << "Enter the employee category:\n"
         << "w: waiter s: singer "
         << "t: singing waiter q: quit\n";
    cin >> choice;
    while (strchr("wstq", choice) == NULL) {
      cout << "please enter a w, s, t, or q: ";
      cin >> choice;
    }

    if (choice == 'q')
      break;

    switch (choice) {
      case 'w':
        lolas[ct] = new Waiter;
        break;
      case 's':
        lolas[ct] = new Singer;
        break;
      case 't':
        lolas[ct] = new SingingWaiter;
        break;
    }

    cin.get();
    lolas[ct]->Set();
  }

  cout << "\nHere is your staff:\n";

  int i;
  for (i = 0; i < ct; i++) {
    cout << endl;
    lolas[i]->Show();
  }

  for (i = 0; i < ct; i++)
    delete lolas[i];

  cout << "bye.\n";

  return 0;
}
