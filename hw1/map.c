#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "terrain.h"

void generate_world(struct world *w)
{
  printf("here\n");
  int i, j;
  struct map **matrix = (struct map **)malloc(401 * sizeof(struct map *));

  for (int k = 0; k < 401; k++)
  {
    matrix[k] = (struct map *)malloc(401 * sizeof(struct map));
  }

  for (i = 0; i < 401; i++)
  {
    for (j = 0; j < 401; j++)
    {
      // w->map[i][j] = (struct map)malloc((21 * 80 * sizeof(char)));
      // m->terrain = (char *)malloc((21 * 80 * sizeof(char)));
      matrix[i][j].terrain = (char *)malloc(21 * 80 * sizeof(char));
      generate_terrain(matrix[i][j].terrain);
      matrix[i][j].x = i;
      matrix[i][j].y = j;
    }
  }
  w->map = matrix;
}

void print_map(struct world *w, int i, int j)
{
  print_terrain(w->map[j][i].terrain);
}

// void free_world(struct world *w)
// {
//   for (int i = 0; i < 401; i++)
//   {
//     for (int j = 0; j < 401; j++)
//     {
//       free(w->map[i][j].terrain);
//     }
//   }
// }