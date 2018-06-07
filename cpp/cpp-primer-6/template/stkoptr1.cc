// test stack of pointers
#include <iostream>
#include <cstdlib> // for rand(), srand()
#include <ctime> // for time()

#include "stacktp1.h"

const int kNum = 10;

int main(int argc, char *argv[]) {
  std::srand(std::time(0)); // randomize rand()
  std::cout << "Please enter stack size: ";
  int stacksize;
  std::cin >> stacksize;

  // create an empty stack with stacksize slots
  // use `const char*' as a type because the array of pointers is
  // initialized to a set of string constants.
  Stack<const char*> st(stacksize);

  // in basket
  const char* in[kNum] = {
    " 1: Hank Gilgamesh", " 2: Kiki Ishtar",
    " 3: Betty Rocker", " 4: Ian Flagranti",
    " 5: Wolfgang Kibble", " 6: Portia Koop",
    " 7: Joy Almondo", " 8: Xaverie Paprika",
    " 9: Juan Moore", "10: Misha Mache"
  };

  // out basket
  const char* out[kNum];

  int processed = 0;
  int nextin = 0;
  while (processed < kNum) {
    if (st.isempty())
      st.push(in[nextin++]);
    else if (st.isfull())
      st.pop(out[processed++]);
    else if (std::rand() % 2 && nextin < kNum) // 50-50 chance
      st.push(in[nextin++]);
    else
      st.pop(out[processed++]);
  }

  for (int i = 0; i < kNum; i++)
    std::cout << out[i] << std::endl;

  std::cout << "bye\n";
  return 0;
}

