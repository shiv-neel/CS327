#include <stdio.h>

typedef enum
{
  read_text,
  write_text,
  read_binary,
  write_binary
} action_t;

typedef struct
{
  int i;
  float f;
} file_data_t;

int main(int argc, char *argv[])
{
  action_t action;
  FILE *file;
  file_data_t data;
  if (argc != 3)
  {
    fprintf(stderr, "Usage [-rt | -wt | -rb | -wb] <file>\n");
    return -1;
  }
  if (argv[1][1] == 'r')
  {
    // read
    if (argv[1][2] == 't')
    {
      // text
      action = read_text;
    }
    else
    {
      // binary
      action = read_binary;
    }
  }
  else
  {
    // write
    if (argv[1][2] == 't')
    {
      // text
      action = write_text;
    }
    else
    {
      // binary
      action = write_binary;
    }
  }

  switch (action)
  {
  case read_text:
    if ((file = fopen(argv[2], "r")))
    {
      data.i = 0;
      data.f = 0;
      fscanf(file, "%d %f\n", data.i, data.f);
      fprintf(file, "Read %d %f\n", data.i, data.f);
    }
    else
    {
      fprintf(stderr, "Failed to open %s\n", argv[2]);
    }
    break;
  case write_text:
    if ((file = fopen(argv[2], "w")))
    {
      data.i = 10;
      data.f = 3.14;
      fprintf(file, "%d %f\n", data.i, data.f);
      fclose(file);
    }
    else
    {
      fprintf(stderr, "Failed to open %s\n", argv[2]);
    }
    break;
  case read_binary:
    if ((file = fopen(argv[2], "r")))
    {
      data.i = 0;
      data.f = 0;
      if (fread(&data, sizeof(data), 1, file) != 1)
      {
        fprintf(stderr, "Error writing to %s\n", argv[2]);
      }
      printf("Read %d %f\n", data.i, data.f);
      fclose(file);
    }
    else
    {
      fprintf(stderr, "Failed to open %s\n", argv[2]);
    }
    break;
  case write_binary:
    if ((file = fopen(argv[2], "w")))
    {
      data.i = 10;
      data.f = 3.14;

      if (fwrite(&data, sizeof(data), 1, file) != 1)
      {
        fprintf(stderr, "Error writing to %s\n", argv[2]);
      }
      fclose(file);
    }
    break;
  }
  return 0;
}