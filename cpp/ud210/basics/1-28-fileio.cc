#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  string line;

  // create an output stream to write to the file append the new
  // lines to the end of the file
  ofstream myfile("input.txt", ios::app);
  if (myfile.is_open()) {
    myfile << "\nI am adding a line.\n";
    myfile.close();
  } else {
    cout << "Unable to open file for writing";
  }

  // create an input stream to write to the file
  ifstream myfilei("input.txt");
  if (myfilei.is_open()) {
    while (getline(myfilei, line)) {
      cout << line << "\n";
    }
    myfilei.close();
  } else {
    cout << "Unable to open file for reading";
  }
  return 0;
}

