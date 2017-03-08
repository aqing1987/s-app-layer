// stack.cpp -- stack member functions
// look at the properties of a stack in a general, abstract way.
// First, a stack holds several items. Next, a stack is characterized
// by the operations you can perform on it.
// 1. you can create an empty stack
// 2. you can add an item to the top of a stack (push an item)
// 3. you can remove an item from the top (pop an item)
// 4. you can check whether the stack is full
// 5. you can check whether the stack is empty
#include "stack.h"

// the default constructor guarantees that all stacks are created
// empty.
Stack::Stack() // create an empty stack
{
  top = 0;
}

bool Stack::isEmpty() const
{
  return top == 0;
}

bool Stack::isFull() const
{
  return top == MAX;
}

bool Stack::push(const Item & item)
{
  if (top < MAX) {
    items[top++] = item;
    return true;
  }
  else {
    return false;
  }
}

bool Stack::pop(Item & item)
{
  if (top > 0) {
    item = items[--top];
    return true;
  }
  else {
    return false;
  }
}