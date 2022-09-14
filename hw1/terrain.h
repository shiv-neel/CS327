#ifndef TERRAIN_H_
#define TERRAIN_H_

void generate_empty_terrain(char *terrain);
void grow(char *terrain, int x, int y, int depth);
void generate_tall_grass(char *terrain);
void generate_roads(char *terrain, int ns_road_idx, int ew_road_idx);
void generate_building(char *terrain, char c, int x, int y);
void generate_obstacles(char *terrain);
void print_terrain(char *terrain);
void generate_terrain(char *terrain, int ns_road_idx, int ew_road_idx);

#endif
