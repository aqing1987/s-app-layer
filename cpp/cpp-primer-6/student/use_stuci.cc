// use_stuc.cc -- using a class with private inheritance
// compile with studentci.cc
// Copyright 2017 Kevin All rights reserved.

#include <iostream>

#include "./studentci.h"

using std::cin;
using std::cout;
using std::endl;

static void set(Student& sa, int n) {
  cout << "Please enter the student's name: ";
  getline(cin, sa);
  cout << "Please enter " << n << " quiz scores:\n";
  for (int i = 0; i < n; i++)
    cin >> sa[i];

  while (cin.get() != '\n')
    continue;
}


int main(int argc, char *argv[]) {
  const int kPupils = 3;
  const int kQuizzes = 5;

  Student ada[kPupils] = {
    Student(kQuizzes), Student(kQuizzes), Student(kQuizzes)
  };

  int i;
  for (i = 0; i < kPupils; ++i)
    set(ada[i], kQuizzes);

  cout << "\nStudent List:\n";
  for (i = 0; i < kPupils; ++i)
    cout << ada[i].Name() << endl;

  cout << "\nResults:";
  for (i = 0; i < kPupils; ++i) {
    cout << endl << ada[i];
    cout << "average: " << ada[i].Average() << endl;
  }

  cout << "Done.\n";

  return 0;
}
