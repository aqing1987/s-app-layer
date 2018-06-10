#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  std::string userName;
  std::cout << "Tell me your nickname";
  std::getline(std::cin, userName);
  std::cout << "Hello " << userName << "\n";
  return 0;
}
