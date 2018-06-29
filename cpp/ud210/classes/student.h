#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
using namespace std;

class Student {
 public:
  void setName(string nameIn);
  void setId(int idIn);
  void setGradDate(int dateIn);
  string getName();
  int getId();
  int getGradDate();
  void print();

 private:
  string name;
  int id;
  int gradDate;
};

#endif /* STUDENT_H_ */

