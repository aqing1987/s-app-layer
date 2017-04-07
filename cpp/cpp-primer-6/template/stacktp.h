// stacktp.h -- a stack template
// Copyright 2017 Kevin All rights reserved.
// Think twice before using template metaprogramming; think about whether the
// average member of your team will be able to underestand your code well enough
// to maintain it.
#ifndef STACKTP_H_
#define STACKTP_H_

template <class Type>
class Stack {
 public:
  Stack();

  bool isempty();
  bool isfull();
  bool push(const Type& item);  // add item to stack
  bool pop(Type& item);  // pop top into item

 private:
  enum {
    kMax = 10,  // constant specific to class
  };
  Type items[kMax];  // holds stack items
  int top;  // index for top stack item
};

template <class Type>
Stack<Type>::Stack() {
  top = 0;
}

template <class Type>
bool Stack<Type>::isempty() {
  return top == 0;
}

template <class Type>
bool Stack<Type>::isfull() {
  return top == kMax;
}

template <class Type>
bool Stack<Type>::push(const Type& item) {
  if (top < kMax) {
    items[top++] = item;
    return true;
  } else {
    return false;
  }
}

template <class Type>
bool Stack<Type>::pop(Type& item) {
  if (top > 0) {
    item = items[--top];
    return true;
  } else {
    return false;
  }
}

#endif  // STACKTP_H_
