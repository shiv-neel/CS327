#include <stdio.h>

struct foo
{
};

int main(int argc, char *argv[])
{
  char c;
  int x, y;
  scanf("%c", &c);
  printf("Read a %c\n", c);

  if (c == 'f')
  {
    scanf("%d %d", &x, &y);
    printf("Fly to map (%d, %d)\n", x, y);
  }
  return 0;
}