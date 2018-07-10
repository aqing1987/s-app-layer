// this stack can only store int data
#include <stdio.h>
#include <malloc.h>

// array used to store data
static int* arr = NULL;
// stack size
static int count;

// create stack, default size 12
int create_array_stack(int sz) {
  arr = (int*)malloc(sz*sizeof(int));
  if (!arr) {
    printf("arr malloc error!\n");
    return -1;
  }
  return 0;
}

// destroy stack
int destroy_array_stack() {
  if (arr) {
    free(arr);
    arr = NULL;
  }

  return 0;
}

void push(int val) {
  arr[count++] = val;
}

int peek() {
  return arr[count-1];
}

// return head value, and remove head
int pop() {
  int ret = arr[count-1];
  count--;
  return ret;
}

int size() {
  return count;
}

int is_empty() {
  return size() == 0;
}

void print_array_stack() {
  if (is_empty()) {
    printf("stack is empty!\n");
    return;
  }

  printf("stack size()=%d\n", size());

  int i = size() - 1;
  while (i >= 0) {
    printf("%d\n", arr[i]);
    i--;
  }
  
}

int main(int argc, char *argv[]) {
  int tmp = 0;

  create_array_stack(12);

  push(10);
  push(20);
  push(30);

  tmp = pop();
  printf("tmp=%d\n", tmp);

  tmp = peek();
  printf("tmp=%d\n", tmp);

  push(40);
  print_array_stack();

  destroy_array_stack();
  return 0;
}

