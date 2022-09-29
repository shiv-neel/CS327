#ifndef TERRAIN_H
#define TERRAIN_H

void generate_empty_terrain(map_t *m);
void grow(map_t *m, int x, int y, int depth);

void generate_tall_grass(map_t *m);
void generate_world_edge_borders(map_t *m);
void generate_roads(map_t *m, int ns_road_idx, int ew_road_idx);
void generate_building(map_t *m, char c);
void generate_obstacles(map_t *m);

void print_terrain(map_t *m);
void generate_terrain(map_t *m);

#endif
