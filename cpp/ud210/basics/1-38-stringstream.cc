/*
 * use stringstream library to convert the string variable to a
 * numeric variable.
 */

#include <iostream>
#include <string>
#include <sstream>

int main(int argc, char *argv[]) {
  std::string strLen;
  float inches = 0;
  float yardage = 0;

  std::cout << "Enter number of inches: ";
  std::getline(std::cin, strLen);
  std::stringstream(strLen) >> inches;
  std::cout << "You entered " << inches << "\n";
  yardage = inches / 36;
  std::cout << "Yardage is " << yardage << "\n";
  return 0;
}

