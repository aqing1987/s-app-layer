// acctabc.cc -- bank account class methods
// implement the methods that don't already have inline definitions.
#include <iostream>

#include "acctabc.h"

using std::cout;
using std::endl;
using std::ios_base;
using std::string;

// Abstract Base Class
AcctABC::AcctABC(const string& s, long an, double bal) {
  fullname_ = s;
  acctnum_ = an;
  balance_ = bal;
}

void AcctABC::Deposit(double amt) {
  if (amt < 0)
    cout << "Negative deposit not allowed; deposit is cancelled.\n";
  else
    balance_ += amt;
}

void AcctABC::Withdraw(double amt) {
  balance_ -= amt;
}

// protected methods for formatting
AcctABC::Formatting AcctABC::SetFormat() const {
  // set up ###.## format
  Formatting f;
  f.flag = cout.setf(ios_base::fixed, ios_base::floatfield);
  f.pr = cout.precision(2);
  return f;
}

void AcctABC::Restore(Formatting& f) const {
  cout.setf(f.flag, ios_base::floatfield);
  cout.precision(f.pr);
}

// Brass methods
void Brass::Withdraw(double amt) {
  if (amt < 0)
    cout << "Withdrawal amount must be positive; withdrawal cancelled.\n";
  else if (amt <= Balance())
    AcctABC::Withdraw(amt);
  else
    cout << "Withdrawal amount of $" << amt
         << " exceeds your balance.\n"
         << "Withdrawal cancelled.\n";
}

void Brass::ViewAcct() const {
  Formatting f = SetFormat();
  cout << "Brass Client: " << FullName() << endl;
  cout << "Account Number: " << AcctNum() << endl;
  cout << "Balance: $" << Balance() << endl;
  Restore(f);
}

// BrassPlus Methods
BrassPlus::BrassPlus(const string& s, long an, double bal,
                     double ml, double r) : AcctABC(s, an, bal) {
  max_loan_ = ml;
  owes_bank_ = 0.0;
  rate_ = r;
}

BrassPlus::BrassPlus(const Brass& ba, double ml, double r) : AcctABC(ba) {
  max_loan_ = ml;
  owes_bank_ = 0.0;
  rate_ = r;
}

void BrassPlus::ViewAcct() const {
  Formatting f = SetFormat();

  cout << "BrassPlus Client: " << FullName() << endl;
  cout << "Account Number: " << AcctNum() << endl;
  cout << "Balance: $" << Balance() << endl;
  cout << "Maximum loan: $" << max_loan_ << endl;
  cout << "Owed to bank: $" << owes_bank_ << endl;
  cout.precision(3);
  cout << "Loan Rate: " << 100 * rate_ << "%\n";
  Restore(f);
}

void BrassPlus::Withdraw(double amt) {
  Formatting f = SetFormat();

  double bal = Balance();
  if (amt <= bal) {
    AcctABC::Withdraw(amt);
  } else if (amt <= bal + max_loan_ - owes_bank_) {
    double advance = amt - bal;
    owes_bank_ += advance * (1.0 + rate_);
    cout << "Bank advance: $" << advance << endl;
    cout << "Finance charge: $" << advance * rate_ << endl;
    Deposit(advance);
    AcctABC::Withdraw(amt);
  } else {
    cout << "Credit limit exceeded. Transaction cancelled.\n";
  }

  Restore(f);
}

