// worktest.cc -- test worker class hierarchy
// Copyright 2017 Kevin All rights reserved.
#include <iostream>

#include "worker0.h"

const int kLim = 4;

int main(int argc, char *argv[]) {
  Waiter bob("Bob Apple", 314L, 5);
  Singer bev("Beverly Hills", 522L, 3);
  Waiter w_temp;
  Singer s_temp;

  Worker* pw[kLim] = {
    &bob, &bev, &w_temp, &s_temp,
  };

  int i;
  for (i = 2; i < kLim; i++)
    pw[i]->Set();

  for (i = 0; i < kLim; i++) {
    pw[i]->Show();
    std::cout << std::endl;
  }

  return 0;
}
