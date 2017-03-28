// brass.cc -- bank account class methods
// Non-constructors can't use the member initializer list syntax. But a derived
// class method can call a public base-class method.
#include <iostream>

#include "brass.h"

using std::cout;
using std::endl;
using std::string;

// formatting stuff
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;

format SetFormat();
void Restore(format f, precis p);

// Brass methods

Brass::Brass(const string &s, long an, double bal) {
  fullname_ = s;
  acctnum_ = an;
  balance_ = bal;
}

void Brass::Deposit(double amt) {
  if (amt < 0)
    cout << "Negative deposit not allowed; deposit is cancelled.\n";
  else
    balance_ += amt;
}

void Brass::Withdraw(double amt) {
  // set up ###.## format
  format initialState = SetFormat();
  precis prec = cout.precision(2);

  if (amt < 0)
    cout << "Withdrawal amount must be positive; withdrawal cancelled.\n";
  else if (amt <= balance_)
    balance_ -= amt;
  else
    cout << "Withdrawal amount of $" << amt
         << " exceeds your balance.\n"
         << "Withdrawal cancelled.\n";

  Restore(initialState, prec);
}

double Brass::Balance() const {
  return balance_;
}

void Brass::ViewAcct() const {
  // set up ###.## format
  format initialState = SetFormat();
  precis prec = cout.precision(2);
  cout << "Client: " << fullname_ << endl;
  cout << "Account Number: " << acctnum_ << endl;
  cout << "Balance: $" << balance_ << endl;
  Restore(initialState, prec); // restore original format
}

// BrassPlus Methods

BrassPlus::BrassPlus(const string &s, long an, double bal,
                     double ml, double r) : Brass(s, an, bal) {
  max_loan_ = ml;
  owes_bank_ = 0.0;
  rate_ = r;
}

// use implicit copy constructor
BrassPlus::BrassPlus(const Brass &ba, double ml, double r) : Brass(ba) {
  max_loan_ = ml;
  owes_bank_ = 0.0;
  rate_ = r;
}

// redefine how ViewAcct() works
void BrassPlus::ViewAcct() const {
  // set up ###.## format
  format initialState = SetFormat();
  precis prec = cout.precision(2);
  // using the scope-resolution operator in a derived-class method to
  // invoke a base-class method is a standard technique.
  // If the code doen'st use the scope-resolution operator, the compiler
  // assumes that ViewAcct() is BrassPlus::ViewAcct(), and this creates a
  // recursive function that has no termination.
  Brass::ViewAcct(); // display base portion
  cout << "Maximum loan: $" << max_loan_ << endl;
  cout << "Owed to bank: $"<< owes_bank_ << endl;

  cout.precision(3); // ###.### format
  cout << "Loan Rate: " << 100 * rate_ << "%\n";
  Restore(initialState, prec); // restore original format
}

// redefine how WithDraw() works
void BrassPlus::Withdraw(double amt) {
  // set up ###.## format
  format initialState = SetFormat();
  precis prec = cout.precision(2);

  // Note than the method uses the base-class Balance() function to determine
  // the original balance. The code doesn't have to use the scope-resolution
  // operator for Balance() because this method has not been redefined in the
  // derived class.
  double bal = Balance();
  if (amt <= bal) {
    Brass::Withdraw(amt);
  } else if (amt <= bal + max_loan_ - owes_bank_) {
    double advance = amt - bal;
    owes_bank_ += advance * (1.0 + rate_);
    cout << "Bank advance: $" << advance << endl;
    cout << "Finance charge: $" << advance * rate_ << endl;
    Deposit(advance);
    Brass::Withdraw(amt);
  } else {
    cout << "Credit limit exceeded. Transaction cancelled.\n";
  }

  Restore(initialState, prec);
}

// sets fixed-point notation and returns the previous flag setting
format SetFormat() {
  // set up ###.## format
  return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

// resets the format and the precision
void Restore(format f, precis p) {
  cout.setf(f, std::ios_base::floatfield);
  cout.precision(p);
}