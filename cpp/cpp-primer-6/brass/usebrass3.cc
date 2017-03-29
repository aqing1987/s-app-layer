// usebrass3.cc -- polymorphic example using an abstract base class
// compile with acctabc.cc
#include <iostream>
#include <string>

#include "acctabc.h"

const int kClients = 4;

int main(int argc, char *argv[]) {
  using std::cin;
  using std::cout;
  using std::endl;

  AcctABC *p_clients[kClients];
  std::string temp;
  long tempnum;
  double tempbal;
  char kind;

  for (int i = 0; i < kClients; i++) {
    cout << "Enter client's name: ";
    getline(cin, temp);
    cout << "Enter client's account number: ";
    cin >> tempnum;
    cout << "Enter opening balance: $";
    cin >> tempbal;
    cout << "Enter 1 for Brass Account or 2 for BrassPlus Account: ";
    while (cin >> kind && (kind != '1' && kind != '2'))
      cout << "Enter either 1 or 2: ";

    if (kind == '1') {
      p_clients[i] = new Brass(temp, tempnum, tempbal);
    } else {
      double tmax, trate;
      cout << "Enter the overdraft limit: $";
      cin >> tmax;
      cout << "Enter the interest rate as a decimal fraction: ";
      cin >> trate;
      p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
    }

    while (cin.get() != '\n')
      continue;
  }

  cout << endl;
  // The polymorphic aspect is provied by the following code
  // If the array member points to a Brass object, Brass::ViewAcct() is invoked
  // If the array member points to a BrassPlus object, BrassPlus::ViewAcct()
  // is invoked.
  for (int i = 0; i < kClients; i++) {
    p_clients[i]->ViewAcct();
    cout << endl;
  }

  // The need for virutal destructors
  // if the destructors are not virtual, then just the destructor corresponding
  // to the pointer type is called. This means that only the Brass destructor
  // would be called, even if the pointer pointed to a BrassPlus object.
  // If the destructors are virtual, the destructor corresponding to the object
  // type is called. So if a pointer points to a BrassPlus object, the BrassPlus
  // destructor is called. And when a BrassPlus destructor finishes, it
  // automaticaly calls the base-class constructor. Thus, using virtual
  // destructor ensures that the correct sequence of destructors is called.
  for (int i = 0; i < kClients; i++) {
    delete p_clients[i]; // free memory
  }
  cout << "Done\n";

  return 0;
}
