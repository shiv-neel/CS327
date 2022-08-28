#include <stdio.h>

/*
running a C file:
gcc <filename.c> -o <compiled file name>
./<compiled file name>
*/

void populate_table(int table[10][10])
{
  int i, j;
  for (j = 0; j < 10; j++)
  {
    for (i = 0; i < 10; i++)
    {
      table[j][i] = i * j;
    }
  }
}

void print_table(int table[10][10])
{
  int i, j;
  for (j = 0; j < 10; j++)
  {
    for (i = 0; i < 10; i++)
    {
      printf("%3d ", table[j][i]); // %d for converting decimal (base10)
      // 3 b4 d creates field width of 3
    }
    printf("\n");
  }
}

int main(int argc, char *argv[])
{
  int t[10][10]; // when you declare a variable like this, it's automatically on the stack
  populate_table(t);
  print_table(t);
  return 0;
}