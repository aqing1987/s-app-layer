#include <iostream>

int main(int argc, char *argv[]) {
  int a = 0, b = 0;
  int post = 0, pre = 0;

  std::cout << "initial values: \t\tpost="
            << post << "\tpre=" << pre << "\n";
  post = a++;
  pre = ++b;
  std::cout << "After one postfix and prefix:\tpost=" << post
            << "\tpre=" << pre << "\n";

  post = a++;
  pre = ++b;
  std::cout << "After two postfix and prefix:\tpost=" << post
            << "\tpre=" << pre << "\n";
  return 0;
}
