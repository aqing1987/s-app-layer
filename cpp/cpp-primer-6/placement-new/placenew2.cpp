// placenew2.cpp -- new, placement new, no delete
// manage memory loations used by placement new and by adding appropriate
// uses of delete and of explicit destructor calls.
// One important fact is the proper order of deletion. The objects constructed
// by placement new should be destroyed in order opposite that in which they
// were constructed. The reason is that, in principle, a later object might
// have dependencies on an earlier object. And the buffer used to hold the
// objects should be freed only after all the contained objects are destroyed.
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
  // fix placement new location
  pc3 = new (buffer + sizeof(JustTesting)) JustTesting("Bad Idea", 6);
  pc4 = new JustTesting("Heap2", 10);

  cout << "Memory contents:\n";
  cout << pc3 << ": ";
  pc3->Show();
  cout << pc4 << ": ";
  pc4->Show();

  delete pc2; // free heap1
  delete pc4; // free heap2
  // explicitly destroy placement new objects
  pc3->~JustTesting(); // destroy object pointed to by pc3
  pc1->~JustTesting(); // destroy object pointed to by pc1
  delete [] buffer; // free buffer
  cout << "Done\n";

  return 0;
}
