// tabtenn1.h -- a table-tennis derived class
#ifndef TABTENN1_H_
#define TABTENN1_H_

#include <string>

using std::string;

// simple base class
class TableTennisPlayer {
 public:
  TableTennisPlayer(const string &fn = "none", const string &ln = "none",
                    bool ht = false);
  void Name() const;
  bool HasTable() const {
    return hasTable;
  }
  void ResetTable(bool v) {
    hasTable = v;
  }

 private:
  string firstname;
  string lastname;
  bool hasTable;

};

// simple derived class
class RatedPlayer : public TableTennisPlayer {
 public:
  RatedPlayer(unsigned int r = 0, const string &fn = "none",
              const string &ln = "none", bool ht = false);
  RatedPlayer(unsigned int r, const TableTennisPlayer &tp);
  unsigned int Rating() const {
    return rating;
  }
  void ResetRating(unsigned int r) {
    rating = r;
  }

 private:
  unsigned int rating;
};

#endif /* TABTENN1_H_ */