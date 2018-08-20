/*
 * It's pretty straightforward. Your goal is to create a function that removes
 * the first and last characters of a string. You're given one parameter, the
 * original string. You don't have to worry with strings with less than two
 * characters.
 * */

#include <iostream>
#include <string>

using namespace std;

// other solution
string sliceString1(string str) {
  return string(str.begin()+1, str.end()-1);
}

string sliceString (string str) {

  return string(str, 1, str.length()-2);
}

int main() {
  cout << sliceString("tuna") << endl;
  return 0;
}