// mytime0.cpp -- implementing Time methods
#include <iostream>
#include "mytime0.h"

Time::Time()
{
  hours = minutes = 0;
}

Time::Time(int h, int m)
{
  hours = h;
  minutes = m;
}

void Time::AddMin(int m)
{
  minutes += m;
  hours += minutes / 60;
  minutes %= 60;
}

void Time::AddHr(int h)
{
  hours += h;
}

void Time::Reset(int h, int m)
{
  hours = h;
  minutes = m;
}

// The reason for making the argument reference is efficiency.
// The code would produce the same results if the Time object were
// passed by value, but it's usually faster and more memory-efficient
// to just pass a reference.
// However, the return value cannot be a reference.
// If the return type were Time &, however, the reference would be to the
// sum object. But the sum object is a local variable and is destroyed when
// the function terminates, so the reference would be a reference to a
// non-existent object.
Time Time::Sum(const Time & t) const
{
  Time sum;
  sum.minutes = minutes + t.minutes;
  sum.hours = hours + t.hours + sum.minutes / 60;
  sum.minutes %= 60;

  return sum;
}

void Time::Show() const
{
  std::cout << hours << " hours, " << minutes << " minutes";
}