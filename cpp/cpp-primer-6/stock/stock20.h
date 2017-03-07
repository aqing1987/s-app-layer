// stock20.h -- augmented version
#ifndef STOCK20_H_
#define STOCK20_H_

#include <string>

class Stock {
 private:
  std::string company;
  long shares;
  double share_val;
  double total_val;
  void set_tot() { total_val = shares * share_val; }

 public:
  Stock(); // default consructor
  Stock(const std::string & co, long n = 0, double pr = 0.0);
  ~Stock(); // noisy destructor

  void buy(long num, double price);
  void sell(long num, double price);
  void update(double price);
  // place the const keyword after the function parentheses, to promise
  // not to change invoking object
  // class functions declared and defined this way are called const
  // member functions.
  // You should make class methods const whenever they don't modify the
  // invoking object.
  void show() const;
  const Stock & topval(const Stock & s) const;
};

#endif