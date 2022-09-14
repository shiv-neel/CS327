#include <stdio.h>
#include <stdlib.h>
#include "terrain.h"
#include "map.h"

int main(int argc, char *argv[])
{

  // char *terrain = malloc(21 * 80 * sizeof(char));

  // generate_empty_terrain(terrain);
  // print_terrain(terrain);

  struct world *w = (struct world *)malloc(sizeof(struct world));
  generate_world(w);
  print_map(w, 0, 0);
  return 0;
}
