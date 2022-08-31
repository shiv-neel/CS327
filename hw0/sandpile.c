#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void print_table(int table[23][23])
{
  int x, y;
  for (int y = 0; y < 23; y++)
  {
    for (int x = 0; x < 23; x++)
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
  printf("-----------------------------------------\n");
}

void initialize_table(int table[23][23], int argc, char *argv[])
{
  int i;
  if (argc > 1 && strcmp(argv[1], "--fps") == 0)
  {
    for (i = 3; i < argc; i += 3)
    {
      int y = atoi(argv[i]);
      int x = atoi(argv[i + 1]);
      int h = atoi(argv[i + 2]);
      table[y][x] = h;
    }
  }
  else
  {
    for (i = 1; i < argc; i += 3)
    {
      int y = atoi(argv[i]);
      int x = atoi(argv[i + 1]);
      int h = atoi(argv[i + 2]);
      table[y][x] = h;
    }
  }
}

void topple_cell(int table[23][23], int x, int y)
{
  int i;
  table[y][x] = 0;
  int neighbors[8][2] = {{y - 1, x - 1}, {y, x - 1}, {y + 1, x - 1}, {y - 1, x}, {y + 1, x}, {y - 1, x + 1}, {y, x + 1}, {y + 1, x + 1}};
  for (i = 0; i < 8; i++)
  {
    int u = neighbors[i][0];
    int v = neighbors[i][1];
    if (u < 0 || u > 21 || v < 0 || v > 21 || table[v][u] == -1)
    {
      continue;
    }
    if (table[v][u] >= 8)
    {
      topple_cell(table, u, v);
    }
    else
    {
      table[v][u] += 1;
    }
  }
}

void drop_sand_on_center(int table[23][23])
{
  if (table[11][11] >= 8)
  {
    topple_cell(table, 11, 11);
  }
  else
  {
    table[11][11] += 1;
  }
}

int main(int argc, char *argv[])
{
  int table[23][23] = {{0}};
  initialize_table(table, argc, argv);
  print_table(table);
  while (1)
  {
    drop_sand_on_center(table);
    print_table(table);
    if (argc > 1 && strcmp(argv[1], "--fps") == 0)
    {
      usleep(1000000 / atoi(argv[2]));
    }
    else
    {
      usleep(1000000);
    }
  }
}

// 30 fps = 0.5s sleep
// 60 fps = 1s sleep
// 10 fps = 1/6
