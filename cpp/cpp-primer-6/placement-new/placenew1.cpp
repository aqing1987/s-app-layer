// placenew1.cpp -- new, placement new, no delete
// There are a couple problems with placement new as used below:
// First, when creating a second object, placement new simply overwrites
// the same location used for the first object with a new object. Not only is
// this rude, it means that the destructor was never called for the first
// object. This, of course, would create real problems if, say, the class used
// dynamic memory allocation for its members.
// Second, using delete with pc2 and pc4 automatically invokes the destructors
// for the two objects that pc2 and pc4 point to. But using delete [] with
// buffer does not invoke the destructors for the objects created with
// placement new.
// It's up to you to manage the memory locations in a buffer that placement
// new populates. To use two different locations, you provide two different
// addresses within the buffer, making sure that the location don't overlap.
#include <iostream>
#include <string>
#include <new>

using namespace std;

const int BUF = 512;

class JustTesting {
 private:
  string words;
  int number;

 public:
  JustTesting(const string & s = "Just Testing", int n = 0) {
    words = s; number = n; cout << words << " constructed\n";
  }
  ~JustTesting() {
    cout << words << " destroyed\n";
  }
  void Show() const {
    cout << words << ", " << number << endl;
  }
};

int main(int argc, char *argv[])
{
  char *buffer = new char[BUF]; // get a block of memory

  JustTesting *pc1, *pc2;

  pc1 = new (buffer) JustTesting; // place object in buffer
  pc2 = new JustTesting("Heap1", 20); // place object in heap

  cout << "Memory block addresses:\n" << "buffer: "
       << (void *)buffer << "   heap: " << pc2 << endl;
  cout << "Memory contents:\n";
  cout << pc1 << ": ";
  pc1->Show();
  cout << pc2 << ": ";
  pc2->Show();

  JustTesting *pc3, *pc4;
  pc3 = new (buffer) JustTesting("Bad Idea", 6);
  pc4 = new JustTesting("Heap2", 10);

  cout << "Memory contents:\n";
  cout << pc3 << ": ";
  pc3->Show();
  cout << pc4 << ": ";
  pc4->Show();

  delete pc2; // free heap1
  delete pc4; // free heap2
  delete [] buffer; // free buffer
  cout << "Done\n";

  return 0;
}
