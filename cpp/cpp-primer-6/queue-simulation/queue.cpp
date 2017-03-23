// queue.cpp -- Queue and Customer methods
#include <cstdlib> // (or stdlib.h) for rand()

#include "queue.h"

// qsize is a const, so it can be initialized to a value, but it can't be
// assigned a value. Therefore, if you want to initialize a const data
// member, you have to do so when the object is created before execution
// reaches the body of the constructor. C++ provides a special syntax for
// doing just that. It's called a member initializer list. The member
// initializer list consists of a comma-separated list of initializers
// preceded by a colon. It's placed after the closing parenthesis of the
// argument list and before the opening bracket of the function body.
// Only constructors can use this initializer-list syntax.
// You have to use this syntax for const class members.
// You also have to use it for class members that are declared as references.
Queue::Queue(int qs) : qsize(qs) {
  front = rear = NULL; // or nullptr
  items = 0;
}

// there's no guarantee that a queue will be empty when it expires.
// Therefore, the class does require an explicit destructor - one that
// deletes all remaining nodes.
Queue::~Queue() {
  Node *temp;
  while (front != NULL) { // while queue is not yet empty
    temp = front; // save address of front item
    front = front->next; // reset pointer to next item
    delete temp; // delete former front
  }
}

bool Queue::isempty() const {
  return items == 0;
}

bool Queue::isfull() const {
  return items == qsize;
}

int Queue::queuecount() const {
  return items;
}

// add item to queue
bool Queue::enqueue(const Item &item) {
  if (isfull())
    return false;

  Node *add = new Node; // create node
  // on failure, new throws std::bad_alloc exception
  add->item = item; // set node data
  add->next = NULL; // or nullptr
  items++;
  if (front == NULL) // if queue is empty
    front = add; // place item at front
  else
    rear->next = add; // else place at rear

  rear = add; // have rear point to new node

  return true;
}

// place front item into item variable and remove from queue
bool Queue::dequeue(Item &item) {
  if (front == NULL)
    return false;

  item = front->item; // set item to first item in queue
  items--;
  Node *temp = front; // save location of first item
  front = front->next; // reset front to next item
  delete temp; // delete former first item

  if (items == 0)
    rear = NULL;

  return true;
}

// customer method

// when is the time at which the customer arrives
// the arrival time is set to when and the processing
// time set to a random value in the range 1 - 3
void Customer::set(long when) {
  processtime = std::rand() % 3 + 1;
  arrive = when;
}