// workermi.h -- working classes with MI
// Copyright 2017 Kevin All rights reserved.
//
// If one class inherits from a nonvirtual base class by more than one route,
// then the class inherits one base-class object for each nonvirtual instance
// of the base class. More ofter, multiple instances of a base class are a
// problem.
// The main change, and the reason for virtual base classes, is that a class
// that inherits from one or more instances of a virtual base class inherits
// just one base-class object.
// introducing MI with a shared ancestor requires introducing virtual base
// classes, altering the rules for constructor initialization lists, and
// possibly recoding the classes if they were written with MI mi mind.
#ifndef WORKERMI_H_
#define WORKERMI_H_

#include <string>

// an abstract base class
class Worker {
 public:
  Worker() : fullname_("no one"), id_(0L) {}
  Worker(const std::string& s, long n) : fullname_(s), id_(n) {}

  virtual ~Worker() = 0;  // pure virtual destructor

  virtual void Set() = 0;
  virtual void Show() const = 0;

 protected:
  virtual void Data() const;
  virtual void Get();

 private:
  std::string fullname_;
  long id_;
};

// a class becomes a virtual base class when a derived class uses the
// keyword virtual when indicating derivation.
class Waiter : virtual public Worker {
 public:
  Waiter() : Worker(), panache_(0) {}
  Waiter(const std::string& s, int n, int p = 0)
      : Worker(s, n), panache_(p) {}
  explicit Waiter(const Worker& wk, int p = 0)
      : Worker(wk), panache_(p) {}

  void Set();
  void Show() const;

 protected:
  void Data() const;
  void Get();

 private:
  int panache_;
};

class Singer : virtual public Worker {
 protected:
  enum {
    kOther, kAlto, kContralto, kSoprano, kBase, kBaritone, kTenor,
  };
  enum {
    kVtypes = 7,
  };

 public:
  Singer() : Worker(), voice_(kOther) {}
  Singer(const std::string& s, long n, int v = kOther)
      : Worker(s, n), voice_(v) {}
  explicit Singer(const Worker& wk, int v = kOther)
      : Worker(wk), voice_(v) {}

  void Set();
  void Show() const;

 protected:
  void Data() const;
  void Get();

 private:
  static char* pv_[kVtypes];  // string equivs of voice types
  int voice_;
};

// multiple inheritance
class SingingWaiter : public Singer, public Waiter {
 public:
  SingingWaiter() {}
  SingingWaiter(const std::string& s, long n, int p = 0, int v = kOther)
      : Worker(s, n), Waiter(s, n, p), Singer(s, n, v) {}
  explicit SingingWaiter(const Worker& wk, int p = 0, int v = kOther)
      : Worker(wk), Waiter(wk, p), Singer(wk, v) {}
  explicit SingingWaiter(const Waiter& wt, int v = kOther)
      : Worker(wt), Waiter(wt), Singer(wt, v) {}
  explicit SingingWaiter(const Singer& wt, int p = 0)
      : Worker(wt), Waiter(wt, p), Singer(wt) {}

  void Set();
  void Show() const;

 protected:
  void Data() const;
  void Get();
};

#endif  // WORKERMI_H_
