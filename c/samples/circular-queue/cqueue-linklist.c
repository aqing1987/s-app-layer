#include <stdio.h>
#include <stdlib.h>

struct queue_item {
  int info;
  struct queue_item *next;
};

struct queue {
  struct queue_item *front;
  struct queue_item *rear;
};

// q points to a queue already allocated, or it is NULL
struct queue* create(struct queue *q) {
  if (q == NULL)
    q = malloc(sizeof(struct queue));

  if (q) {
    q->front = NULL;
    q->rear = NULL;
  } else {
    printf("malloc err!\n");
  }

  return q;
}

struct queue_item* makenode(int item) {
  struct queue_item* p = (struct queue_item*)malloc(sizeof(struct queue_item));
  if (p) {
    p->info = item;
    // there is no link yet, so make it clear to avoid any surprises later
    p->next = NULL;
  } else {
    printf("malloc error\n");
  }

  return p;
}

void addLast(struct queue *q, int item) {
  struct queue_item* p = makenode(item);

  if (q->front == NULL) {
    q->front = q->rear = p;
    q->front->next = q->front;
    q->rear->next = q->rear;
  } else {
    q->rear->next = p;
    p->next = q->front;
    q->rear = p;
  }
}

int delFirst(struct queue *q) {
  struct queue_item *p = q->front;

  if (q->front == NULL) {
    printf("\nEmpty Queue\n");
  } else {
    int temp = q->front->info;

    if (q->front->next != q->front) {
      q->front = q->front->next;
      q->rear->next = q->front;
    } else {
      q->front = NULL;
    }

    free(p);
    return temp;
  }

  return -1;
}

int main(int argc, char *argv[]) {
  struct queue *premium, normal;

  premium = create(NULL); // allocate the queue structure
  create(&normal); // use an allocated structure

  int index = 0;
  for (index = 0; index < 1000; index++) {
    addLast(premium, index);
  }

  for (index = 0; index < 1000; index++) {
    printf("%d\n", delFirst(premium));
  }

  addLast(&normal, 20);
  addLast(&normal, 30);
  printf("%i\n", delFirst(&normal));
  printf("%i\n", delFirst(&normal));
  delFirst(&normal);

  return 0;
}