// Copyright 2017 Neil All rights reserved.
//
// Given the importance of examing all aspects of this problem, it
// would be useful to be able t try different stack sizes.
// Now the stack constructor accepts an optional size argument.
// This involves using a dynamic array internally, so the class
// now needs a destructor, a copy constructor, and an assignment
// operator. Also the definition shortens the code by making several
// of the methods inline.
//
// we can use Stack inside the template declaration and inside the
// template function definitions, but outside the class, as when
// identifying return types and when using the scope-resolution
// operator, you need to use the full Stack<Type> form.

#ifndef STACKTP1_H_
#define STACKTP1_H_

template <class Type>
class Stack {
 public:
  explicit Stack(int ss = kMax);
  Stack(const Stack& st);
  ~Stack() {
    delete [] items;
  }

  bool isempty() {
    return top == 0;
  }
  bool isfull() {
    return top == stacksize;
  }
  bool push(const Type& item);  // add item to stack
  bool pop(Type& item);  // pop top into item
  Stack& operator=(const Stack& st);

 private:
  enum {kMax = 10}; // constant specific to class
  int stacksize;
  Type* items; // holds stack items
  int top;  // index for top stack item  
};

template <class Type>
Stack<Type>::Stack(int ss) : stacksize(ss), top(0) {
  items = new Type[stacksize];
}

template <class Type>
Stack<Type>::Stack(const Stack& st) {
  stacksize = st.stacksize;
  top = st.top;
  items = new Type[stacksize];
  for (int i = 0; i < top; i++)
    items[i] = st.items[i];
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

template <class Type>
Stack<Type>& Stack<Type>::operator=(const Stack<Type>& st) {
  if (this == &st)
    return *this;

  delete [] items;
  stacksize = st.stacksize;
  top = st.top;
  items = new Type[stacksize];
  for (int i = 0; i < top; i++)
    items[i] = st.items[i];

  return *this;
}

#endif /* STACKTP1_H_ */
