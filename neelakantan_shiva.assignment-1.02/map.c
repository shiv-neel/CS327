#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "map.h"
#include "terrain.h"

void generate_empty_world(struct world *w)
{
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
      matrix[i][j].terrain = (char *)malloc(21 * 80 * sizeof(char));
      matrix[i][j].x = i;
      matrix[i][j].y = j;
    }
  }

  // setting random horizontal roads for each row of world
  srand(time(0));
  for (i = 0; i < 401; i++)
  {

    int y = (rand() % 18) + 1;
    for (j = 0; j < 401; j++)
    {
      matrix[i][j].ew_road_idx = y;
    }
  }

  // setting random vertical rows for each col of world

  srand(time(0));
  for (j = 0; j < 401; j++)
  {
    int x = (rand() % 77) + 1;
    matrix[0][j].ns_road_idx = x;
  }

  for (i = 1; i < 401; i++)
  {
    for (j = 0; j < 401; j++)
    {
      matrix[i][j].ns_road_idx = matrix[i - 1][j].ns_road_idx;
    }
  }

  w->map = matrix;
  generate_terrain(&w->map[w->x][w->y]);
}

void print_map(struct world *w, int x, int y)
{
  printf("Loading map, this may take a few seconds...\n");
  print_terrain(&w->map[y][x]);
  printf("(%d, %d)\n", x - 200, y - 200);
}

void display_north(struct world *w)
{
  if (w->y == 0)
  {
    printf("Cannot go any further north.\n");
    return;
  }
  if (!(w->map[(w->y) - 1][(w->x)].terrain[0]))
  {
    generate_terrain(&w->map[(w->y) - 1][(w->x)]);
  }
  print_map(w, (w->x), (w->y) - 1);
  w->y -= 1;
}

void display_south(struct world *w)
{
  if (w->y == 400)
  {
    printf("Cannot go any further south.\n");
    return;
  }
  if (!(w->map[(w->y) + 1][(w->x)].terrain[0]))
  {
    generate_terrain(&w->map[(w->y) + 1][(w->x)]);
  }
  print_map(w, (w->x), (w->y) + 1);
  w->y += 1;
}

void display_west(struct world *w)
{
  if (w->x == 0)
  {
    printf("Cannot go any further west.\n");
    return;
  }
  if (!(w->map[(w->y)][(w->x) - 1].terrain[0]))
  {
    generate_terrain(&w->map[(w->y)][(w->x) - 1]);
  }
  print_map(w, (w->x) - 1, w->y);
  w->x -= 1;
}

void display_east(struct world *w)
{
  if (w->x == 400)
  {
    printf("Cannot go any further east.\n");
    return;
  }
  if (!(w->map[(w->y)][(w->x) + 1].terrain[0]))
  {
    generate_terrain(&w->map[(w->y)][(w->x) + 1]);
  }
  print_map(w, (w->x) + 1, w->y);
  w->x += 1;
}

void fly_to(struct world *w, int x, int y)
{
  x += 200;
  y += 200;
  if (x < 0 || x > 400 || y < 0 || y > 400)
  {
    printf("Please enter a coordinate within (-200, -200) and (200, 200).");
    return;
  }
  if (!(w->map[y][x].terrain[0]))
  {
    generate_terrain(&w->map[y][x]);
  }
  print_map(w, x, y);
  w->x = x;
  w->y = y;
}

void free_world(struct world *w)
{
  for (int i = 0; i < 401; i++)
  {
    for (int j = 0; j < 401; j++)
    {
      free(w->map[i][j].terrain);
    }
  }
}