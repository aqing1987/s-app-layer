/*
Check to see if a string has the same amount of 'x's and 'o's. The method must
return a boolean and be case insensitive. The string can contain any char.
e.g.
XO("ooxx") => true
XO("xooxx") => false
XO("ooxXm") => true
XO("zpzpzpp") => true // when no 'x' and 'o' is present should return true
XO("zzoo") => false
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool XO(const char* str) {
  int count_x = 0;
  int count_o = 0;

  unsigned int i = 0;
  for (i = 0; i < strlen(str); i++) {
    if (str[i] == 'x' || str[i] == 'X') {
      count_x++;
    } else if (str[i] == 'o' || str[i] == 'O') {
      count_o++;
    }
  }
  return count_o == count_x;
}

// others'
bool XO1(const char* str) {
  unsigned x = 0, o = 0;
  const char* p = str;

  while (*p) {
    if (tolower(*p) == 'x')
      x++;
    else if (tolower(*p) == 'o')
      o++;

    p++;
  }

  return x == o;
}

int main(int argc, char const *argv[]) {
  printf("%d\n", XO1("ooxx"));
  printf("%d\n", XO1("xooxx"));
  printf("%d\n", XO1("ooxXm"));
  printf("%d\n", XO1("zpzpzpp"));
  printf("%d\n", XO1("zzoo"));
  return 0;
}
