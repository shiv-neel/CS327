// preprocessor directive
#include <stdio.h>
#include <string.h>

// @param argc = number of args in argv
// @param argv = string[]
// @return type int
int main(int argc, char *argv[])
{
  if (argc == 1)
    printf("Hello World!");
  else
  {
    for (int i = 1; i < argc; i++)
    {
      if (!strcmp(argv[i], "Putin"))
      {
        printf("Goodbye %s\n", argv[i]);
      }
      else
      {
        printf("Hello %s\n", argv[i]);
      }
    }
  }
  return 0;
}