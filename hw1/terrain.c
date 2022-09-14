#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "terrain.h"

void generate_empty_terrain(char *terrain)
{
  // initially an "empty" terrain
  for (int i = 0; i < 21; i++)
  {
    for (int j = 0; j < 80; j++)
    {
      terrain[i * 80 + j] = '.';
    }
  }

  // adding borders int i, j;
  for (int i = 0; i < 21; i++)
  {
    terrain[i * 80] = '%';
    terrain[i * 80 + 79] = '%';
  }
  for (int j = 0; j < 80; j++)
  {
    terrain[j] = '%';
    terrain[j + 80 * 20] = '%';
  }
}

void grow(char *terrain[21][80], int x, int y, int depth)
{
  if (!depth)
    return;
  if (x < 79 && x > 0 && y < 20 && y > 0)
  {
    terrain[y][x] = ":";
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
      grow(terrain, x + i, y + j, depth - 1);
    }
  }
}

void generate_tall_grass(char *terrain[21][80])
{
  srand(time(0));
  int x1 = (rand() % 61) + 10;
  int x2 = (rand() % 61) + 10;
  int depth1 = (rand() % 5) + 5;
  int depth2 = (rand() % 5) + 5;
  grow(terrain, x1, 19, depth1);
  grow(terrain, x2, 1, depth2);
}

void generate_roads(char *terrain[21][80])
{
  srand(time(0));
  int x = (rand() % 77) + 1;
  int y = (rand() % 18) + 1;

  // N-S road
  for (int i = 0; i < 21; i++)
  {
    terrain[i][x] = "#";
  }
  for (int j = 0; j < 80; j++)
  {
    terrain[y][j] = "#";
  }
}

void generate_pokemon_center(char *terrain[21][80])
{
  srand(time(0));
  int x = (rand() % 76) + 2;
  int y = (rand() % 17) + 2;
  while (strcmp(terrain[y][x], ".") || strcmp(terrain[y + 1][x], ".") || strcmp(terrain[y][x + 1], ".") || strcmp(terrain[y + 1][x + 1], ".") || (strcmp(terrain[y - 1][x], "#") && strcmp(terrain[y + 2][x], "#") && strcmp(terrain[y][x - 1], "#") && strcmp(terrain[y][x + 2], "#")))
  {
    x = (rand() % 76) + 2;
    y = (rand() % 17) + 2;
  }
  terrain[y][x] = terrain[y + 1][x] = terrain[y][x + 1] = terrain[y + 1][x + 1] = "C";
}

void generate_pokemart(char *terrain[21][80])
{
  srand(time(0));
  int x = (rand() % 76) + 2;
  int y = (rand() % 17) + 2;
  while (strcmp(terrain[y][x], ".") || strcmp(terrain[y + 1][x], ".") || strcmp(terrain[y][x + 1], ".") || strcmp(terrain[y + 1][x + 1], ".") || (strcmp(terrain[y - 1][x], "#") && strcmp(terrain[y + 2][x], "#") && strcmp(terrain[y][x - 1], "#") && strcmp(terrain[y][x + 2], "#")))
  {
    x = (rand() % 76) + 2;
    y = (rand() % 17) + 2;
  }
  terrain[y][x] = terrain[y + 1][x] = terrain[y][x + 1] = terrain[y + 1][x + 1] = "M";
}

void generate_obstacles(char *terrain[21][80])
{
  srand(time(0));
  int numBoulders = (rand() % 10) + 5;
  int numTrees = (rand() % 10) + 5;
  int x, y;
  for (int i = 0; i < numBoulders; i++)
  {
    x = (rand() % 76) + 2;
    y = (rand() % 17) + 2;
    while (strcmp(terrain[y][x], "."))
    {
      x = (rand() % 76) + 2;
      y = (rand() % 17) + 2;
    }
    terrain[y][x] = "%";
  }

  for (int j = 0; j < numTrees; j++)
  {
    x = (rand() % 76) + 2;
    y = (rand() % 17) + 2;
    while (strcmp(terrain[y][x], "."))
    {
      x = (rand() % 76) + 2;
      y = (rand() % 17) + 2;
    }
    terrain[y][x] = "^";
  }
}

void print_terrain(char *terrain)
{
  printf("\033[1m");
  printf("Loading map, this may take a few seconds...\n");
  int i, j;
  for (int i = 0; i < 21; i++)
  {
    for (int j = 0; j < 80; j++)
    {
      if (terrain[i * 80 + j] == 'C') // pokemon center
      {
        printf("\033[1;31m");
      }
      else if (terrain[i * 80 + j] == 'M') // pokemart
      {
        printf("\033[1;36m");
      }
      else if (terrain[i * 80 + j] == ':') // tall grass
      {
        printf("\033[0;32m");
      }
      else if (terrain[i * 80 + j] == '^') // trees
      {
        printf("\033[1;32m");
      }
      else if (terrain[i * 80 + j] == '#') // roads
      {
        printf("\033[1;33m");
      }
      else if (terrain[i * 80 + j] == '%') // boulders
      {
        printf("\033[1;35m");
      }
      else if (terrain[i * 80 + j] == '@') // player
      {
        printf("\033[1;34m");
      }
      else
      {
        printf("\033[0m");
      }

      printf("%c", terrain[i * 80 + j]);
    }
    printf("\n");
  }

  printf("\033[0m");
}

void generate_terrain(char *terrain)
{
  generate_empty_terrain(terrain);

  // generate_tall_grass(terrain);

  // generate_roads(terrain);

  // generate_pokemon_center(terrain);
  // generate_pokemart(terrain);
  // generate_obstacles(terrain);
}

// int main(int argc, char *argv[])
// {
//   char *terrain = (char *)malloc(21 * 80 * sizeof(char));
//   generate_terrain(terrain);
//   print_terrain(terrain);
// }
