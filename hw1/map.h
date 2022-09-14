#ifndef MAP_H_

#define MAP_H_
struct map
{
  char *terrain;
  int x;
  int y;
};

struct world
{
  struct map **map;
};

void generate_world(struct world *w);
void print_map(struct world *w, int i, int j);
void free_world(struct world *w);
#endif