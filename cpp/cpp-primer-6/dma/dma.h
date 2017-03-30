// dma.h -- inheritance and dynamic memory allocation
// Copyright 2017 Kevin All rights reserved.
//
// if a base class uses dynamic memory allocation, and the derived class does
// not itself use dynamic memory allocation, you needn't take any special steps.
//
// When both the base class and the derived class use dynamic memory allocation,
// the derived-class destructor, copy constructor, and assignment operator all
// must use their base-class counterparts to handle the base-class component.
// This common requirement is accomplished three different ways. For a
// destructor it is done automatically. For a constructor, it is accomplished
// by invoking the base-class copy constructor in the memory initialization
// list, or else the default constructor is invoked automatically. For the
// assignment operator, it is accomplished by using the scope-resolution
// operator in an explicit call of the base-class assignment operator.
#ifndef DMA_H_
#define DMA_H_

#include <iostream>

// Bae Class Using DMA
class baseDMA {
 public:
  explicit baseDMA(const char* l = "null", int r = 0);
  baseDMA(const baseDMA& rs);
  virtual ~baseDMA();

  baseDMA& operator=(const baseDMA& rs);
  friend std::ostream& operator<<(std::ostream& os, const baseDMA& rs);

 private:
  char* label_;
  int rating_;
};

// derived class without DMA
// no destructor needed
// uses implicit copy constructor
// uses implicit assignment operator
class lacksDMA : public baseDMA {
 public:
  explicit lacksDMA(const char* c = "blank", const char* l = "null", int r = 0);
  lacksDMA(const char* c, const baseDMA& rs);

  friend std::ostream& operator<<(std::ostream& os, const lacksDMA& ls);

 private:
  enum {
    COL_LEN = 40
  };
  char color_[COL_LEN];
};

// derived class with DMA
class hasDMA : public baseDMA {
 public:
  explicit hasDMA(const char* s = "none", const char* l = "null", int r = 0);
  hasDMA(const char* s, const baseDMA& rs);
  hasDMA(const hasDMA& hs);
  ~hasDMA();

  hasDMA& operator=(const hasDMA& hs);
  friend std::ostream& operator<<(std::ostream& os, const hasDMA& hs);

 private:
  char* style_;
};

#endif  // DMA_H_