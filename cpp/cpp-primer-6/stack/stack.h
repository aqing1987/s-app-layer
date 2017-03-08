// stack.h -- class definition for the stack ADT
// the private section shows that the stack is implemented by
// using an array, but the public section doesn't reveal that fact.
// Thus, you can replace the array with, say, a dynamic array without
// changing the class interface.
#ifndef STACK_H_
#define STACK_H_

// use typedef to make Item the same as unsigned long
// If you want, say, a stack of doubles or of a structure type, you
// can change the typedef and leave the class declaration and method
// definitions unaltered.
typedef unsigned long Item;

class Stack {
 private:
  enum {MAX = 10}; // constant specific to class
  Item items[MAX]; // holds stack items
  int top; // index for top stack item

 public:
  Stack();

  bool isEmpty() const;
  bool isFull() const;
  // push returns false if stack already is full, true otherwise
  bool push(const Item & item); // add item to stack
  // pop() returns false if stack already is empty, true otherwise
  bool pop(Item & item); // pop top into item
};

#endif