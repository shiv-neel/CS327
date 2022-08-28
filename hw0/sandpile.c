#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int t[22][22];
  initialize_table(t, argc, argv);
  print_table(t);
}

void initialize_table(int table[22][22], int argc, char *argv[])
{
  int i;
  for (i = 0; i < argc; i += 3)
  {
    int x = atoi(argv[i]);
    int y = atoi(argv[i + 1]);
    int h = atoi(argv[i + 2]);
    table[y][x] = h;
  }
}

void print_table(int *table[22][22])
{
  int x, y;
  for (int y = 0; y < 22; y++)
  {
    for (int x = 0; x < 22; x++)
    {
      if (table[y][x] == -1)
      {
        printf("# ");
      }
      else
      {
        printf("%d ", table[y][x]);
      }
    }
    printf("\n");
  }
}
