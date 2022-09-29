#include <stdio.h>
#include <string.h>

struct foo
{
  int i;
  float f;
  char s[80];
};

void init_foo(struct foo *foobar)
{
  foobar->i = 3; // same as: (*foobar).i = 3;
  foobar->f = 4.5;
  strcpy(foobar->s, "string");
}

// two stars == address of an address
void swap_right(int *i, int *j)
{
  int temp = *i;
  *i = *j;
  *j = temp;
  printf("int swap: i=%d, j=%d\n", *i, *j);
}

int main(int argc, char *argv[])
{
  struct foo foobar;
  init_foo(&foobar); // & to grab the memory address. * is the actual pointer to the data
  printf("%d, %f, %s\n", foobar.i, foobar.f, foobar.s);
}