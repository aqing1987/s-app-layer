/*
 * enable coredump:
 *   ulimit -c unlimited
 *
 * debug:
 *   gdb a.out core
 */
#include <stdio.h>
#include <string.h>

static void wild_ptr_dereference() {
  char* p;
  p[0] = 'a';
}

static void null_ptr_dereference() {
  int* p = NULL;
  //printf("%d\n", *p);
  *p = 1;
}

static void wirte_to_readonly_memory() {
  char* s = "Hello world";
  *s = 'H';
}

static void check_buffer_overflow() {
  char A[8] = "";
  unsigned short B = 1979;

  // "excessive" is 9 characters long and encodes to 10 bytes
  // including the null terminator, but A can take only 8 bytes.
  // By failing to check the length of the string, it also overwrites
  // the value of B.
  strcpy(A, "excessive");
}

static void check_stack_overflow() {
  return check_stack_overflow();
}

int main(int argc, char *argv[]) {
  printf("Usage: %s [item]\n\titem:\n\t"\
         "1 - wild pointer dereference\n\t"\
         "2 - null pointer dereference\n\t" \
         "3 - write to read-only memory\n\t"\
         "4 - buffer overflow\n\t"\
         "5 - stack overflow\n\t"\
         "\nInput item: ", argv[0]);
  int item = 0;
  scanf("%d", &item);
  printf("item = %d\n", item);

  switch (item) {
    case 1:
      wild_ptr_dereference();
      break;
    case 2:
      null_ptr_dereference();
      break;
    case 3:
      wirte_to_readonly_memory();
      break;
    case 4:
      check_buffer_overflow();
      break;
    case 5:
      check_stack_overflow();
      break;
    default:
      break;
  }
  return 0;
}
