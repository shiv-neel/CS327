#ifndef MAP_H_

#define MAP_H_
struct map
{
  char *t;
};

struct world
{
  struct map *map[401][401];
};
void generate_world(struct world *w);
void free_world(struct world *w);
#endif