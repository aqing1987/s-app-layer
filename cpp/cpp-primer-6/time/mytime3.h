// mytime3.h -- Time class with friends
#ifndef MYTIME3_H_
#define MYTIME3_H_

#include <iostream>

class Time {
 private:
  int hours;
  int minutes;

 public:
  Time();
  Time(int h, int m = 0);
  void AddMin(int m);
  void AddHr(int h);
  void Reset(int h = 0, int m = 0);
  Time operator+(const Time & t) const;
  Time operator-(const Time & t) const;
  Time operator*(double n) const;

  // Caution:
  // You use the friend keyword only in the prototype found in the class
  // declaration. You don't use it in the function definition unless the
  // definition is also the prototype.
  friend Time operator*(double m, const Time & t) {
    return t * m;
  }
  friend std::ostream & operator<<(std::ostream & os, const Time & t);
};

#endif