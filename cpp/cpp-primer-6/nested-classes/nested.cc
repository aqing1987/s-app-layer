// using a queue that has a nested class
#include <iostream>

#include <string>
#include "queuetp.h"

int main(int argc, char *argv[]) {
  using std::string;
  using std::cin;
  using std::cout;

  QueueTP<string> cs(5);
  string temp;

  while (!cs.isFull()) {
    cout << "Please enter your name. You will be "
        "served in the order of arrival.\n"
        "name: ";

    getline(cin, temp);
    cs.Enqueue(temp);
  }

  cout << "The Queue is full. Processing begins!\n";
  while (!cs.isEmpty()) {
    cs.Dequeue(temp);
    cout << "Now processing " << temp << "...\n";
  }
  return 0;
}

