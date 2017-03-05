// stock00.h -- Stock class interface
// version 00
#ifndef STOCK00_H_
#define STOCK00_H_

#include <string>

class Stock { // class declaration
  // because one of the main precepts of OOP is to hide the
  // data, data items normally go into the private section.
 private:
  std::string company;
  long shares;
  double share_val;
  double total_val;
  // typically, you use private member functions to handle implementation
  // details that don't form part of the public interface.
  // Any function with a definition in the class declaration automatically
  // becomes an inline function. Thus, Stock::set_tot() is an inline
  // function.
  // Class declaration often use inline functions for short member functions
  void set_tot() {
    total_val = shares * share_val;
  }

  // the member functions that consitute the class interface go into
  // the public section
 public:
  void acquire(const std::string & co, long n, double pr);
  void buy(long num, double price);
  void sell(long num, double price);
  void update(double price);
  void show();
}; // note semicolon at the end

#endif