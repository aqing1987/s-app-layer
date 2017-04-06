// worker0.h -- working classes
#ifndef WORKER0_H_
#define WORKER0_H_

#include <string>

// an abstract base class
class Worker {
 public:
  Worker() : fullname_("no one"), id_(0L) {}
  Worker(const std::string& s, long n) : fullname_(s), id_(n) {}
  virtual ~Worker() = 0; // pure virtual destructor

  virtual void Set();
  virtual void Show() const;

 private:
  std::string fullname_;
  long id_;
};

class Waiter : public Worker {
 public:
  Waiter() : Worker(), panache_(0) {}
  Waiter(const std::string& s, int n, int p = 0) : Worker(s, n), panache_(p) {}
  Waiter(const Worker& wk, int p = 0) : Worker(wk), panache_(p) {}

  void Set();
  void Show() const;

 private:
  int panache_;
};

class Singer : public Worker {
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
  Singer(const Worker& wk, int v = kOther)
      : Worker(wk), voice_(v) {}

  void Set();
  void Show() const;

 private:
  static char* pv_[kVtypes]; // string equivs of voice types
  int voice_;
};

#endif  // WORKER0_H_
