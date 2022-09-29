#ifndef MAP_H
#define MAP_H

typedef struct map
{
  char *terrain;
  int x; // non-shifted x-cor of map (0-400)
  int y; // non-shifted x-cor of map (0-400)
  int ns_road_idx;
  int ew_road_idx;
} map_t;

typedef struct world
{
  map_t **map;
  int x; // non-shifted x-cor of current map (0-400)
  int y; // non-shifted x-cor of current map (0-400)
} world_t;

void generate_empty_world(struct world *w);
void print_map(struct world *w, int i, int j);

void display_north(struct world *w);
void display_south(struct world *w);
void display_west(struct world *w);
void display_east(struct world *w);

void fly_to(struct world *w, int x, int y);

void free_world(struct world *w);

#endif