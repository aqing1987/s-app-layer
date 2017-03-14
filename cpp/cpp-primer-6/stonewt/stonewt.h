// stonewt.h -- definition for the Stonewt class
#ifndef STONEWT_H_
#define STONEWT_H_

class Stonewt {
 private:
  // pounds per stone
  // enum provides a convenient way to define class-specific constants,
  // provided that they are integers. Or you could use the following alternative:
  // static const int Ls_per_stn = 14;
  enum {
    Lbs_per_stn = 14
  };

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
};

#endif