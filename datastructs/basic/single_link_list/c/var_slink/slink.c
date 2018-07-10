#include <stdio.h>
#include <malloc.h>

struct node {
  void* p;
  struct node* next;
};

static struct node* phead = NULL;

static struct node* create_node(void* pval) {
  struct node* pnode = NULL;
  pnode = (struct node*)malloc(sizeof(struct node));
  if (!pnode) return NULL;

  pnode->p = pval;
  pnode->next = NULL;

  return pnode;
}

static void destroy_single_link() {
  struct node* pnode = NULL;

  while (phead != NULL) {
    pnode = phead;
    phead = phead->next;
    free(pnode);
  }
}

// insert to head position
static struct node* push(void* pval) {
  struct node* pnode = NULL;

  pnode = create_node(pval);
  pnode->next = phead;
  phead = pnode;

  return phead;
}

// return head value and remove head node
static void* pop() {
  if (!phead) {
    printf("remove failed! link is empty!\n");
    return NULL;
  }

  void* pret;
  struct node* pnode;
  pret = phead->p;
  pnode = phead;
  phead = phead->next;
  free(pnode);

  return pret;
}

// return head value
static void* peek() {
  if (!phead) {
    printf("peek failed! linke is empty!\n");
    return NULL;
  }

  return phead->p;
}

// return node number
static int size() {
  int count = 0;
  struct node* pnode = phead;

  while (pnode != NULL) {
    pnode = pnode->next;
    count++;
  }

  return count;
}

static int is_empty() {
  return phead == NULL;
}

// print and clear link
static void print_single_link() {
  if (is_empty()) {
    printf("stack is empty\n");
    return;
  }

  printf("statck size() = %d\n", size());

  struct node* pnode = NULL;
  while (phead != NULL) {
    printf("%d\n", phead->p);
    pnode = phead;
    phead = phead->next;
    free(pnode);
  }
}

int main(int argc, char *argv[]) {
  int tmp = 0;

  push(10);
  push(20);
  push(30);

  // return and remove node
  tmp = pop();
  printf("tmp=%d\n", tmp);

  // only check no delete
  tmp = peek();
  printf("tmp=%d\n", tmp);

  push(40);
  print_single_link();

  destroy_single_link();

  return 0;
}


