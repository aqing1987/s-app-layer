// stonewt1.h -- revised definition for the Stonewt class
#ifndef STONEWT1_H_
#define STONEWT1_H_

class Stonewt {
 private:
  enum {
    Lbs_per_stn = 14
  }; // pounds per stone

  int stone; // whole stones
  double pds_left; // fractional pounds
  double pounds; // entire weight in pounds

 public:
  Stonewt(double lbs); // constructor for double pounds
  Stonewt(int stn, double lbs); // constructor for stone, lbs
  Stonewt(); // default constructor
  ~Stonewt();
  void show_lbs() const; // show weight in pounds format
  void show_stn() const; // show weight in stone format

  // conversion functions
  // format:
  // operator typeName();
  // 1. The conversion function must be a class method
  // 2. The conversion function must not specify a return type
  // 3. The conversion function must have no arguments
  // Note that each function returns the desired value, even though
  // there is no declared return type.
  // with C++11, you can declare a conversion operator as explicit.
  // Caution:
  //   You should use implicit conversion functions with care. Often
  //   a function that can only be invoked explicitly is the best choice.
  explicit operator int() const;
  explicit operator double() const;
};

#endif