// usedma.cc -- inheritance, friends, and DMA
// Copyright 2017 Kevin All rights reserved.
// compile with dma.cc

#include <iostream>

#include "./dma.h"

int main(int argc, char *argv[]) {
  using std::cout;
  using std::endl;

  baseDMA shirt("Portabelly", 8);
  lacksDMA balloon("red", "Blimpo", 4);
  hasDMA map("Mercator", "Buffalo Keys", 5);

  cout << "Displaying baseDMA objects:\n";
  cout << shirt << endl;

  cout << "Displaying lacksDMA object:\n";
  cout << balloon << endl;

  cout << "Displaying hasDMA objects:\n";
  cout << map << endl;

  lacksDMA ballonn2(balloon);
  cout << "Result of lacksDMA copy:\n";
  cout << ballonn2 << endl;

  hasDMA map2;
  map2 = map;
  cout << "Result of hasDMA assignment:\n";
  cout << map2 << endl;

  return 0;
}
