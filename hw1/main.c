#include <stdio.h>
#include <stdlib.h>
#include "terrain.h"
#include "map.h"

int main(int argc, char *argv[])
{

  struct world *w = (struct world *)malloc(sizeof(struct world));
  w->x = 200;
  w->y = 200;
  generate_empty_world(w);
  print_map(w, w->x, w->y);
  // fly_to(w, 4, 5);
  // fly_to(w, 72, -50);
  // fly_to(w, 4, 5);
  // display_north(w);
  char input = 'a';
  int x, y;

  while (input != 'q')
  {
    scanf("%c", &input);
    if (input == 'n')
    {
      printf("travelling north...\n");
      display_north(w);
    }
    else if (input == 's')
    {
      printf("travelling south...\n");
      display_south(w);
    }
    else if (input == 'w')
    {
      printf("travelling west...");
      display_west(w);
    }
    else if (input == 'e')
    {
      printf("travelling east...\n");
      display_east(w);
    }
    else if (input == 'f')
    {
      scanf("%d %d", &x, &y);
      printf("flying to (%d, %d)...\n", x, y);
      fly_to(w, x, y);
    }
  }

  return 0;
}
