// dma.cc -- dma class methods
// Copyright 2017 Kevin All rights reserved.

#include "./dma.h"

#include <cstring>

// baseDMA methods =============================================================

baseDMA::baseDMA(const char* l, int r) {
  label_ = new char[strlen(l) + 1];
  std::strcpy(label_, l);
  rating_ = r;
}

baseDMA::baseDMA(const baseDMA& rs) {
  label_ = new char[std::strlen(rs.label_) + 1];
  std::strcpy(label_, rs.label_);
  rating_ = rs.rating_;
}

baseDMA::~baseDMA() {
  delete [] label_;
}

baseDMA& baseDMA::operator=(const baseDMA& rs) {
  if (this == &rs)
    return *this;

  delete [] label_;
  label_ = new char[std::strlen(rs.label_) + 1];
  std::strcpy(label_, rs.label_);
  rating_ = rs.rating_;

  return *this;
}

std::ostream& operator<<(std::ostream& os, const baseDMA& rs) {
  os << "Label: " << rs.label_ << std::endl;
  os << "Rating: " << rs.rating_ << std::endl;

  return os;
}

// lacksDMA methods ============================================================

lacksDMA::lacksDMA(const char* c, const char* l, int r)
    : baseDMA(l, r) {
  std::strncpy(color_, c, COL_LEN - 1);
  color_[COL_LEN - 1] = '\0';
}

std::ostream& operator<<(std::ostream& os, const lacksDMA& ls) {
  os << dynamic_cast<const baseDMA&>(ls);
  os << "Color: " << ls.color_ << std::endl;

  return os;
}

// hasDMA methods ==============================================================

hasDMA::hasDMA(const char* s, const char* l, int r)
    : baseDMA(l, r) {
  style_ = new char[std::strlen(s) + 1];
  std::strcpy(style_, s);
}

hasDMA::hasDMA(const char* s, const baseDMA& rs)
    : baseDMA(rs) {
  style_ = new char[std::strlen(s) + 1];
  std::strcpy(style_, s);
}

// invoke base class copy constructor
hasDMA::hasDMA(const hasDMA& hs)
    : baseDMA(hs) {
  style_ = new char[std::strlen(hs.style_) + 1];
  std::strcpy(style_, hs.style_);
}

hasDMA::~hasDMA() {
  delete [] style_;
}

hasDMA& hasDMA::operator=(const hasDMA& hs) {
  if (this == &hs)
    return *this;

  baseDMA::operator=(hs);  // copy base portion

  delete [] style_;  // prepare for new style_
  style_ = new char[std::strlen(hs.style_) + 1];
  std::strcpy(style_, hs.style_);

  return *this;
}

std::ostream& operator<<(std::ostream& os, const hasDMA& hs) {
  // use a type cast to match operator<<(ostream&, const baseDMA&)
  os << dynamic_cast<const baseDMA&>(hs);
  os << "Style: " << hs.style_ << std::endl;

  return os;
}
