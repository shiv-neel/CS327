#include <stdio.h>

int main(int argc, char *argv[])
{
  int a[10];
  /*
    int must be at least 4 bytes
    *(a+5) == a[5]
  */

  int m[5][5];
  int *p = m;
  /*
  this gives us a linear, contiguous range of one-dimensional memory

  index of m[1][3] = p + 8;
  */

  char *s;
  /*
  strings are character arrays that are terminated by the null byte '\0'
  `s` is a pointer to a string literal. literal is read-only
  */
  s = "Hello";
  s = "World";
  printf("%s\n", s);
}