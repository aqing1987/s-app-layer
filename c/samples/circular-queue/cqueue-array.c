#include <stdio.h>

#define MAX_ITEMS    10
typedef struct circularQueue_s {
  int first;
  int last;
  int validItems;
  int data[MAX_ITEMS];
} circularQueue_t;

void initializeQueue(circularQueue_t *theQueue);
int isEmpty(circularQueue_t *theQueue);
int putItem(circularQueue_t *theQueue, int theItemValue);
int getItem(circularQueue_t *theQueue, int *theItemValue);
void printQueue(circularQueue_t *theQueue);

void initializeQueue(circularQueue_t *theQueue) {
  int i;
  theQueue->validItems  =  0;
  theQueue->first       =  0;
  theQueue->last        =  0;

  for (i = 0; i < MAX_ITEMS; i++) {
    theQueue->data[i] = 0;
  }

  return;
}

int isEmpty(circularQueue_t *theQueue) {
  if (theQueue->validItems == 0)
    return 1;
  else
    return 0;
}

int putItem(circularQueue_t *theQueue, int theItemValue) {
  if (theQueue->validItems >= MAX_ITEMS) {
    printf("The queue is full\n");
    printf("You cannot add items\n");
    return -1;
  } else {
    theQueue->validItems++;
    theQueue->data[theQueue->last] = theItemValue;
    theQueue->last = (theQueue->last+1) % MAX_ITEMS;
  }

  return 0;
}

int getItem(circularQueue_t *theQueue, int *theItemValue) {
  if (isEmpty(theQueue)) {
    printf("isempty\n");
    return -1;
  } else {
    *theItemValue = theQueue->data[theQueue->first];
    theQueue->first = (theQueue->first+1) % MAX_ITEMS;
    theQueue->validItems--;
    return 0;
  }
}

void printQueue(circularQueue_t *theQueue) {
  int aux, aux1;

  aux  = theQueue->first;
  aux1 = theQueue->validItems;
  while (aux1 > 0) {
    printf("Element #%d = %d\n", aux, theQueue->data[aux]);
    aux = (aux+1) % MAX_ITEMS;
    aux1--;
  }

  return;
}

int main(void) {
  int i;
  int readValue;
  circularQueue_t myQueue;

  initializeQueue(&myQueue);
  for (i = 0; i < MAX_ITEMS + 1; i++) {
    putItem(&myQueue, i);
  }
  printQueue(&myQueue);

  for (i = 0; i < MAX_ITEMS/2; i++) {
    getItem(&myQueue, &readValue);
    printf("readValue = %d\n", readValue);
  }
  printQueue(&myQueue);

  return 0;
}