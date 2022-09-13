#ifndef TERRAIN_H_
#define TERRAIN_H_

void generate_empty_terrain(char *terrain);
void grow(char *terrain[21][80], int x, int y, int depth);
void generate_tall_grass(char *terrain[21][80]);
void generate_roads(char *terrain[21][80]);
void generate_pokemon_center(char *terrain[21][80]);
void generate_obstacles(char *terrain[21][80]);
void print_terrain(char *terrain);
void generate_terrain(char *terrain);

#endif
