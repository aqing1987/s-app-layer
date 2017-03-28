// brass.h -- bank account classes
// Note:
// If you redefine a base-class method in a derived class, the usual practice
// is to declare the base-class method as virtual.
// this makes the program choose the method version based on object type
// instead of the type of a reference or pointer. It's also the usual practice
// to declare a virtual destructor for the base class.
// the keyword virtual is used just in the method prototypes in the class
// declaration, not in the method definitions.
#ifndef BRASS_H_
#define BRASS_H_

#include <string>

// Brass Account Class
class Brass {
 public:
  Brass(const std::string & s = "Nullbody", long an = -1, double bal = 0.0);
  // virtual destructor
  // this is to make sure that the correct sequence of destructors is called
  // when a derived object is destroyed.
  virtual ~Brass() {
  }

  void Deposit(double amt);
  double Balance() const;
  // these methods are now termed virtual methods
  // It is the common practice to declare as virtual in the base class those
  // methods that might be redefined in a derived class. When a method is
  // declared virtual in a base class, it is automatically virtual in the
  // derived class, but it is a good idea to document which functions are
  // virtual by using the keyword virtual in the derived class declarations, too
  virtual void Withdraw(double amt);
  virtual void ViewAcct() const;

 private:
  std::string fullname_;
  long acctnum_;
  double balance_;
};

// BrassPlus Account Class
// You can encounter situations in which you want a method to behave differently
// for the derived class than it does for the base class. That is, the way a
// particular method behaves may depend on the object that invokes it. This more
// sophisticated behavior is termed polymorphic("having many forms") because you
// can have multiple behaviors for a method, depending on the context. There are
// two key mechanisms for implementing polymorphic public inheritance:
// 1. Redefining base-class methods in a derived class
// 2. Using virutal methods
class BrassPlus : public Brass {
 public:
  BrassPlus(const std::string &s = "Nullbody", long an = -1, double bal = 0.0,
            double ml = 500, double r = 0.11125);
  BrassPlus(const Brass &ba, double ml = 500, double r = 0.11125);

  virtual void ViewAcct() const;
  virtual void Withdraw(double amt);
  void ResetMax(double m) {
    max_loan_ = m;
  }
  void ResetRate(double r) {
    rate_ = r;
  }
  void ResetOwes() {
    owes_bank_ = 0;
  }

 private:
  double max_loan_;
  double rate_;
  double owes_bank_;
};

#endif /* BRASS_H_ */