#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "terrain.h"

void generate_world(struct world *w)
{
  int i, j;
  for (i = 0; i < 401; i++)
  {
    for (j = 0; j < 401; j++)
    {
      w->map[i][j] = malloc(sizeof(struct map));
      w->map[i][j]->t = malloc((21 * 80 * sizeof(char)));
      // generate_terrain(w->map[i][j]->t);
    }
  }
}

void print_map(struct world *w, int i, int j)
{
  print_terrain(w->map[i][j]->t);
}

void free_world(struct world *w)
{
  for (int i = 0; i < 401; i++)
  {
    for (int j = 0; j < 401; j++)
    {
      free(w->map[i][j]->t);
      free(w->map[i][j]);
    }
  }
}