// hello3.cc: x
// Description: a program that prints the immortal saying "hello world"
// many times and illustrates some cout flags

#include <iostream>
// we need the following include for setw() in some c++ implementations
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]) {
  // set up cout to left-align
  cout << setiosflags(ios::left);

      // the first for-loop will handle the rows
  for (int i = 0; i < 6; i++) {
    // the second for-loop will handle the columns
    for (int j = 0; j < 4; j++) {
      // setw(int) sets the column width
      cout << setw(17) << "hello, world";
    }
    // this next line is a part of the first for loop and causes the new line
    cout << endl;
  }

  return 0;
}
