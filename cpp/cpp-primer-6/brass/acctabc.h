// acctabc.h -- bank account classes
// abstract base class (ABC)
// C++ has a way to provide an unimplemented function by using a pure
// virtual function. A pure virtual function has = 0 at the end of its
// declaration.
// When a class declaration contains a pure virtual function, you can't create
// an object of that class. The idea is that classes with pure virtual function
// exist solely to serve as base classes.
// For a class to be a genuine ABC, it has to have at least one pure virtual
// function.
// But C++ allows even a pure virtual function to have a definition.
// In short, the = 0 in the prototype indicates that the class is an abstract
// base class and that the class doesn't necessarily have to define the function
//
// This class should contain all methods and data members that are common to
// both the Brass and the BrassPlus classes. The methods that are to work
// differently for the BrassPlus class than they do for the Brass class should
// be declared as virtual functions.
// This file declares the AcctABC class (an ABC) and the Brass and BrassPlus
// classes (both concrete classes).
#ifndef ACCTABC_H_
#define ACCTABC_H_

#include <iostream>
#include <string>

// Abstract Base Class
class AcctABC {
 public:
  AcctABC(const std::string& s = "nullbody", long an = -1, double bal = 0.0);
  virtual ~AcctABC() {
  }

  void Deposit(double amt);
  double Balance() const {
    return balance_;
  }
  virtual void Withdraw(double amt) = 0; // pure virtual function
  virtual void ViewAcct() const = 0; // pure virtual function

  // protected access control can be quite useful for member functions,
  // giving derived classes access to internal functions that are not
  // available publicly.
  // protected methods are methods that derived-class methods can call but
  // that are not part of the public interface for derived-class objects.
 protected:
  struct Formatting {
    std::ios_base::fmtflags flag;
    std::streamsize pr;
  };
  const std::string& FullName() const {
    return fullname_;
  }

  long AcctNum() const {
    return acctnum_;
  }

  Formatting SetFormat() const;
  void Restore(Formatting& f) const;

 private:
  std::string fullname_;
  long acctnum_;
  double balance_;
};

// Brass Account Class
class Brass : public AcctABC {
 public:
  Brass(const std::string& s = "nullbody", long an = -1,
        double bal = 0.0) : AcctABC(s, an, bal) {
  }
  virtual ~Brass() {
  }

  virtual void Withdraw(double amt);
  virtual void ViewAcct() const;
};

// Brass Plus Account Class
class BrassPlus : public AcctABC {
 public:
  BrassPlus(const std::string& s = "nullbody", long an = -1,
            double bal = 0.0, double ml = 500, double r = 0.10);
  BrassPlus(const Brass& ba, double ml = 500, double r = 0.1);

  void ResetMax(double m) {
    max_loan_ = m;
  }

  void ResetRate(double r) {
    rate_ = r;
  }

  void ResetOwes() {
    owes_bank_ = 0;
  }

  virtual void ViewAcct() const;
  virtual void Withdraw(double amt);

 private:
  double max_loan_;
  double rate_;
  double owes_bank_;
};

#endif /* ACCTABC_H_ */