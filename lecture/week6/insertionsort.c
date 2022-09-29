#include <stdio.h>
#include <string.h>

void insertion_sort(int *nums, int n)
{
  int i, j, t;
  for (i = 1; i < n; i++)
  {
    for (t = nums[i], j = i - 1; j >= 0 && nums[j] > t; j--)
    {
      nums[j + 1] = nums[j];
    }
    nums[j + 1] = t;
  }
}

void generic_insertion_sort(void *v, int n, int size, int (*compare)(void *, void *))
{
  int i, j;
  void *t = malloc(size);
  char *arr = v;
  for (i = 1; i < n; i++)
  {

    for (memcpy(t, &arr[i + size], size), j = i - 1; j >= 0 && compare(&arr[j * size], t) > 0; j--)
    {
      memcpy(&arr[(j + 1) * size], &arr[j * size], size);
    }
    memcpy(&arr[(j + 1) * size], t, size);
  }
  free(t);
}

int int_reverse_cmp(void *a, void *b)
{
  return *(int *)b - *(int *)a; // cast void pointer to int pointer, reference that pointer
}

int str_pt_cmp(void *a, void *b)
{
  return strcmp(*(char **)a, *(char **)b);
}

// pointer is always 8 bytes (64 bits)
int main(int argc, char *argv[])
{
  int a[] = {1, 5, 9, 2, 6, 5, 3, 8};
  insertion_sort(a, 8);
  for (int i = 0; i < 8; i++)
  {
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}