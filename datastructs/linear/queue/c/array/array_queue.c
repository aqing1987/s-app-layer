// this queue can only operate int data
#include <stdio.h>
#include <malloc.h>

static int* arr = NULL;
static int count;

int create_array_queue(int sz) {
  arr = (int*)malloc(sz*sizeof(int));
  if (!arr) {
    printf("arr malloc error!\n");
    return -1;
  }
  count = 0;
  return 0;
}

int destroy_array_queue() {
  if (arr) {
    free(arr);
    arr = NULL;
  }

  return 0;
}

// put to the tail
void enqueue(int val) {
  arr[count++] = val;
}

// return front data
int front() {
  return arr[0];
}

int dequeue() {
  int i = 0;
  int ret = arr[0];

  count--;
  while (i < count) {
    i++;
    arr[i-1] = arr[i];
  }

  return ret;
}

int size() {
  return count;
}

int is_empty() {
  return count == 0;
}

int main(int argc, char *argv[]) {
  int tmp = 0;

  create_array_queue(12);

  enqueue(10);
  enqueue(20);
  enqueue(30);

  tmp = dequeue();
  printf("tmp=%d\n", tmp);

  tmp = front();
  printf("tmp=%d\n", tmp);

  enqueue(40);
  printf("is_empt()=%d\n", is_empty());
  printf("size()=%d\n", size());

  while (!is_empty()) {
    printf("%d\n", dequeue());
  }

  destroy_array_queue();
  return 0;
}



