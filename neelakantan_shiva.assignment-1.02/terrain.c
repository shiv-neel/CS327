#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "map.h"
#include "terrain.h"

void generate_empty_terrain(map_t *m)
{
  // initially an "empty" terrain
  for (int i = 0; i < 21; i++)
  {
    for (int j = 0; j < 80; j++)
    {
      m->terrain[i * 80 + j] = '.';
    }
  }
}

void generate_borders(map_t *m)
{
  for (int i = 0; i < 21; i++)
  {
    m->terrain[i * 80] = '%';
    m->terrain[i * 80 + 79] = '%';
  }
  for (int j = 0; j < 80; j++)
  {
    m->terrain[j] = '%';
    m->terrain[j + 80 * 20] = '%';
  }
}

void grow(map_t *m, int x, int y, int depth)
{
  if (!depth)
    return;
  if (x < 79 && x > 0 && y < 20 && y > 0)
  {
    m->terrain[y * 80 + x] = ':';
  }
  srand(time(0));
  for (int j = -1; j <= 1; j++)
  {
    for (int i = -1; i <= 1; i++)
    {
      if ((!i && !j))
        continue;
      if (x + i > 79 && x + i < 0 && y + j > 20 && y + j < 0)
      {
        continue;
      }
      grow(m, x + i, y + j, depth - 1);
    }
  }
}

void generate_tall_grass(map_t *m)
{
  srand(time(0));
  int x1 = (rand() % 61) + 15;
  int x2 = (rand() % 61) + 15;
  int depth1 = (rand() % 5) + 5;
  int depth2 = (rand() % 5) + 5;
  grow(m, x1, 19, depth1);
  grow(m, x2, 1, depth2);
}

// TODO FIX
void generate_world_edge_borders(map_t *m)
{
  int i;
  if (m->x == 0)
  {
    for (i = 0; i < 21; i++)
    {
      m->terrain[i * 80] = '%';
    }
  }
  if (m->x == 400)
  {
    for (i = 0; i < 21; i++)
    {
      m->terrain[i * 80 + 79] = '%';
    }
  }
  if (m->y == 0)
  {
    for (i = 0; i < 80; i++)
    {
      m->terrain[i] = '%';
    }
  }
  if (m->y == 400)
  {
    for (i = 0; i < 80; i++)
    {
      m->terrain[i * 21 + 20] = '%';
    }
  }
}

void generate_roads(map_t *m, int ns_road_idx, int ew_road_idx)
{
  int i, j;
  for (i = 0; i < 21; i++)
  {
    for (j = 0; j < 80; j++)
    {
      if (i == ew_road_idx || j == ns_road_idx)
        m->terrain[i * 80 + j] = '#';
    }
  }

  if (m->x == 0 || m->y == 0 || m->x == 400 || m->y == 400)
  {
    printf("current %d %d\n", m->x, m->y);
    // generate_world_edge_borders(m);
  }
}

void generate_building(map_t *m, char c)
{
  int map_x = m->x;
  int map_y = m->y;

  srand(time(0));
  int d = abs(map_x - 200) + abs(map_y - 200);
  int formula = (((-45 * d) / 200) + 50);
  int random = rand() % formula;
  if (formula < random)
  {
    return; // do not generate building
  }

  int x = (rand() % 76) + 2;
  int y = (rand() % 17) + 2;
  while ((m->terrain[y * 80 + x] != '.') || (m->terrain[(y + 1) * 80 + x] != '.') || (m->terrain[y * 80 + (x + 1)] != '.') || (m->terrain[(y + 1) * 80 + (x + 1)] != '.') || ((m->terrain[(y - 1) * 80 + x] != '#') && (m->terrain[(y + 2) * 80 + x] != '#') && (m->terrain[y * 80 + (x - 1)] != '#') && (m->terrain[y * 80 + (x + 2)] != '#')))
  {
    x = (rand() % 76) + 2;
    y = (rand() % 17) + 2;
  }
  m->terrain[y * 80 + x] = m->terrain[(y + 1) * 80 + x] = m->terrain[y * 80 + (x + 1)] = m->terrain[(y + 1) * 80 + (x + 1)] = c;
}

void generate_obstacles(map_t *m)
{
  srand(time(0));
  int numBoulders = (rand() % 10) + 5;
  int numTrees = (rand() % 10) + 5;
  int x, y;
  for (int i = 0; i < numBoulders; i++)
  {
    x = (rand() % 76) + 2;
    y = (rand() % 17) + 2;
    while (m->terrain[y * 80 + x] != '.')
    {
      x = (rand() % 76) + 2;
      y = (rand() % 17) + 2;
    }
    m->terrain[y * 80 + x] = '%';
  }

  for (int j = 0; j < numTrees; j++)
  {
    x = (rand() % 76) + 2;
    y = (rand() % 17) + 2;
    while (m->terrain[y * 80 + x] == '.')
    {
      x = (rand() % 76) + 2;
      y = (rand() % 17) + 2;
    }
    m->terrain[y * 80 + x] = '^';
  }
}

void print_terrain(map_t *m)
{
  printf("\033[1m");
  int i, j;
  for (int i = 0; i < 21; i++)
  {
    for (int j = 0; j < 80; j++)
    {
      if (m->terrain[i * 80 + j] == 'C') // pokemon center
      {
        printf("\033[1;31m");
      }
      else if (m->terrain[i * 80 + j] == 'M') // pokemart
      {
        printf("\033[1;36m");
      }
      else if (m->terrain[i * 80 + j] == ':') // tall grass
      {
        printf("\033[0;32m");
      }
      else if (m->terrain[i * 80 + j] == '^') // trees
      {
        printf("\033[1;32m");
      }
      else if (m->terrain[i * 80 + j] == '#') // roads
      {
        printf("\033[1;33m");
      }
      else if (m->terrain[i * 80 + j] == '%') // boulders
      {
        printf("\033[1;35m");
      }
      else if (m->terrain[i * 80 + j] == '@') // player
      {
        printf("\033[1;34m");
      }
      else
      {
        printf("\033[0m");
      }

      printf("%c", m->terrain[i * 80 + j]);
    }
    printf("\n");
  }

  printf("\033[0m");
}

void generate_terrain(map_t *m)
{
  int ns_road_idx = m->ns_road_idx;
  int ew_road_idx = m->ew_road_idx;
  char *terrain = m->terrain;

  generate_empty_terrain(m);
  generate_borders(m);

  generate_tall_grass(m);

  generate_obstacles(m);
  generate_roads(m, ns_road_idx, ew_road_idx);

  generate_building(m, 'C');
  generate_building(m, 'M');
}
