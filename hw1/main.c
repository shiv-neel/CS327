#include <stdio.h>
#include <stdlib.h>
#include "terrain.h"
#include "map.h"

int main(int argc, char *argv[])
{

  char *terrain = malloc(21 * 80 * sizeof(char));

  generate_empty_terrain(terrain);
  // print_terrain(terrain);

  struct world *w;
  generate_world(w);

  return 0;
}
